// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnShot);

class ABaseWeapon;
class ABasePlayer;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AIMTRAININGPROJECT_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UWeaponComponent();
	void Shoot();
	FOnShot OnShot;
	ABaseWeapon* GetWeapon() const { return Weapon; }

protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<ABaseWeapon> WeaponClass;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName AttachGripPointName = TEXT("GripPoint");

private:

	UPROPERTY()
		ABaseWeapon* Weapon = nullptr;
	UPROPERTY()
		ABasePlayer* Player = nullptr;
	void SpawnWeapon();
};
