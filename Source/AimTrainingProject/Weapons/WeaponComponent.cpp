// Aim Training Game. Fedosov Vladislav

#include "WeaponComponent.h"
#include "AimTrainingProject/Weapons/BaseWeapon.h"
#include "AimTrainingProject/Player/BasePlayer.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
}

void UWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;

	Weapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponClass);
	if (!Weapon) return;
	Player = Cast<ABasePlayer>(GetOwner());
	if (!Player) return;

	FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(Player->GetHandsMesh(), AttachRules, AttachGripPointName);
}

void UWeaponComponent::Shoot()
{
	if (!Weapon) return;
	OnShot.Broadcast();
	Weapon->Shoot();
}

