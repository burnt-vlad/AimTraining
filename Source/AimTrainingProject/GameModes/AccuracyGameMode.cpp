// Aim Training Game. Fedosov Vladislav

#include "AccuracyGameMode.h"
#include "AimTrainingProject/Player/PlayerControllers/AccuracyPlayerController.h"
#include "AimTrainingProject/Player/PlayerStates/AccuracyPlayerState.h"
#include "AimTrainingProject/Weapons/BaseWeapon.h"

DEFINE_LOG_CATEGORY_STATIC(LogAccuracyGameMode, All, All);

AAccuracyGameMode::AAccuracyGameMode()
{

}

void AAccuracyGameMode::StartPlay()
{
    Super::StartPlay();
    ABaseWeapon* PlayerWeapon = GetPlayerWeapon();
    ActivateRandomTarget();
    if (PlayerWeapon)
    {
        PlayerWeapon->OnShot.AddUObject(this, &AAccuracyGameMode::AddShotsNum);
        PlayerWeapon->OnHit.AddUObject(this, &AAccuracyGameMode::AddHitsNum);
        PlayerWeapon->OnHit.AddUObject(this, &AAccuracyGameMode::ActivateRandomTarget);
    }
}

void AAccuracyGameMode::AddHitsNum()
{
    const auto PlayerController = GetPlayerController();
    const auto PlayerState = Cast<AAccuracyPlayerState>(PlayerController->PlayerState);
    if (!PlayerState) return;
    PlayerState->AddHitsNum();
    PlayerState->PrintStat();
}

void AAccuracyGameMode::AddShotsNum()
{
    const auto PlayerController = GetPlayerController();
    const auto PlayerState = Cast<AAccuracyPlayerState>(PlayerController->PlayerState);
    if (!PlayerState) return;
    PlayerState->AddShotsNum();
    PlayerState->PrintStat();
}
