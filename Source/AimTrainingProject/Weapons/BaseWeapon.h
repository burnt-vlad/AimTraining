// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

class USkeletalMeshComponent;
class ATestGameMode;
class ATarget;
class USoundCue;

DECLARE_MULTICAST_DELEGATE(FOnShot);
DECLARE_MULTICAST_DELEGATE(FOnHit);

UCLASS()
class AIMTRAININGPROJECT_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:

	ABaseWeapon();
	virtual void Shoot();
	FOnShot OnShot;
	FOnHit OnHit;

protected:

	void MakeShot();
	APlayerController* GetPlayerController() const;
	void MakeHit(FHitResult& HitResult);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* WeaponMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
		float ShotDistance = 5000.f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* ShotSound;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
		USoundCue* HitSound;
};
