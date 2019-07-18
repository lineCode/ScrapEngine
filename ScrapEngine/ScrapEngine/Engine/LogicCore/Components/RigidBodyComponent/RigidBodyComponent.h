#pragma once

#include <Engine/LogicCore/Components/SComponent.h>
#include <Engine/LogicCore/Components/MeshComponent/MeshComponent.h>
#include <Engine/Physics/RigidBody/RigidBody.h>

namespace ScrapEngine
{
	namespace Core
	{
		class RigidBodyComponent : public SComponent
		{
		private:
			Physics::RigidBody* rigidbody_ = nullptr;

			MeshComponent* attached_mesh_ = nullptr;

			friend class TriggerComponent;
		public:
			RigidBodyComponent(Physics::RigidBody* rigidbody);
			virtual ~RigidBodyComponent();

			//This methods will be used when the rigidbody is static and the user move the object with it
			//They will have no effect with a Rigidbody
			void set_component_location(const SVector3& location) override;
			void set_component_rotation(const SVector3& rotation) override;
			//If the user is really sure to change the position, will use this method
			void modify_rigidbody_location(const SVector3& location) const;

			void attach_to_mesh(MeshComponent* mesh);
			void update_transform(float factor) const;
			void set_rigidbody_type(Physics::RigidBody_Types type) const;

			float get_bounciness() const;
			void set_bounciness(float bounce_factor) const;

			float get_friction_coefficient() const;
			void set_friction_coefficient(float coefficient) const;

			bool get_allowed_to_sleep() const;
			void set_allowed_to_sleep(bool allowed) const;

			void apply_force_to_center(const SVector3& force) const;
			void apply_torqe(const SVector3& force) const;

			void cancel_rigidbody_forces() const;
		};
	}
}