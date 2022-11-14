// Aim Training Game. Fedosov Vladislav

#include "BasePlayer.h"
#include "Camera/CameraComponent.h"
#include "AimTrainingProject/Weapons/WeaponComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPCharacter, All, All);

ABasePlayer::ABasePlayer()
{
    PrimaryActorTick.bCanEverTick = true;

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(GetRootComponent());

    HandsMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HandsMesh");
    HandsMesh->SetupAttachment(Camera);

    WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
}

void ABasePlayer::BeginPlay()
{
    Super::BeginPlay();
    AnimInstance = HandsMesh->GetAnimInstance();
    WeaponComponent->OnShot.AddUObject(this, &ABasePlayer::OnShot);
}

void ABasePlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("LookUp", this, &ABasePlayer::LookUp);
    PlayerInputComponent->BindAxis("LookRight", this, &ABasePlayer::LookRight);
    PlayerInputComponent->BindAction("Shoot", IE_Pressed, WeaponComponent, &UWeaponComponent::Shoot);
}

void ABasePlayer::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

void ABasePlayer::LookRight(float Value)
{
    AddControllerYawInput(Value);
}

void ABasePlayer::OnShot()
{
    if (!AnimInstance && !ShootAnimMontage) return;
    AnimInstance->Montage_Play(ShootAnimMontage, 1.f);
}

