#pragma once

#include <Engine/Physics/CollisionWorld/DynamicsWorld/DiscreteDynamicsWorld.h>
#include <Engine/Physics/RigidBody/RigidBody.h>
#include <vector>
#include <Engine/Physics/CollisionBody/CollisionBody.h>

namespace ScrapEngine
{
	namespace Physics
	{
		class PhysicsManager
		{
		private:
			DiscreteDynamicsWorld* p_world_ = nullptr;

			std::vector<RigidBody*> created_rigidbodies_;
			std::vector<CollisionBody*> created_collisionbodies_;

			RigidBody* create_rigidbody(const Core::SVector3& start_position,
			                            float mass, CollisionShape* c_shape) const;

			CollisionBody* create_collision_body(const Core::SVector3& start_position,
			                                     CollisionShape* c_shape) const;
		public:
			PhysicsManager();
			~PhysicsManager();

			//Class stuff
			void update_physics(float delta_time) const;
			void remove_collider(CollisionBody* collider);
			void remove_rigidbody(RigidBody* rigidbody);

			//Standard collider (is not moved from the engine, basically a trigger)
			CollisionBody* create_box_trigger(const Core::SVector3& size,
			                                  const Core::SVector3& start_position);

			//RigidBody
			RigidBody* create_box_rigidbody(const Core::SVector3& size,
			                                const Core::SVector3& start_position,
			                                float mass = 0.f);

			RigidBody* create_sphere_rigidbody(float radius,
			                                   const Core::SVector3& start_position,
			                                   float mass = 0.f);

			RigidBody* create_capsule_rigidbody(float radius,
			                                    float height,
			                                    const Core::SVector3& start_position,
			                                    float mass = 0.f);
		};
	}
}