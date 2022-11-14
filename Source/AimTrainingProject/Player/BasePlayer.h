// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayer.generated.h"

class UCameraComponent;
class UWeaponComponent;
class UAnimMontage;
class UAnimInstance;

UCLASS()
class AIMTRAININGPROJECT_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ABasePlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	USkeletalMeshComponent* GetHandsMesh() const { return HandsMesh; };

protected:

	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		USkeletalMeshComponent* HandsMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
		UWeaponComponent* WeaponComponent;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		UAnimMontage* ShootAnimMontage;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
		UAnimInstance* AnimInstance;

private:

	void LookUp(float Value);
	void LookRight(float Value);
	void OnShot();
};
