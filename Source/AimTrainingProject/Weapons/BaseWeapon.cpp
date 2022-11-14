// Aim Training Game. Fedosov Vladislav

#include "BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "AimTrainingProject/Targets/BaseTarget.h"
#include "DrawDebugHelpers.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All);

ABaseWeapon::ABaseWeapon()
{

    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);

}

void ABaseWeapon::Shoot()
{
    MakeShot();
}

APlayerController* ABaseWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return nullptr;
    const auto PlayerController = Player->GetController<APlayerController>();
    if (!PlayerController) return nullptr;
    return PlayerController;
}

void ABaseWeapon::MakeShot()
{
    if (!GetWorld()) return;

    OnShot.Broadcast();
    UGameplayStatics::PlaySound2D(GetWorld(), ShotSound);

    const auto PlayerController = GetPlayerController();
    if (!PlayerController) return;

    FVector CameraLocation;
    FRotator CameraRotation;
    PlayerController->GetPlayerViewPoint(CameraLocation, CameraRotation);

    const FVector ShotStartPoint = CameraLocation;
    const FVector ShotDirection = CameraRotation.Vector();
    const FVector ShotEndPoint = ShotStartPoint + ShotDirection * ShotDistance;


    FHitResult HitResult;
    GetWorld()->LineTraceSingleByChannel(HitResult, ShotStartPoint, ShotEndPoint, ECollisionChannel::ECC_Visibility);

    if (HitResult.bBlockingHit)
    {
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.f, 24, FColor::Red, false, 5.f);
        MakeHit(HitResult);
    }
}

void ABaseWeapon::MakeHit(FHitResult& HitResult)
{
    const auto DamagedActor = HitResult.GetActor();
    if (!DamagedActor)  return;
    const auto Target = Cast<ABaseTarget>(DamagedActor);
    if (!Target) return;
    if (DamagedActor == Target)
    {
        Target->DeactivateTarget();
        OnHit.Broadcast();
        UGameplayStatics::PlaySound2D(GetWorld(), HitSound);
    }
}


