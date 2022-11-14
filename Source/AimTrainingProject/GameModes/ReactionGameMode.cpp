// Aim Training Game. Fedosov Vladislav

#include "ReactionGameMode.h"
#include "AimTrainingProject/Player/PlayerControllers/ReactionPlayerController.h"
#include "AimTrainingProject/Player/PlayerStates/ReactionPlayerState.h"
#include "AimTrainingProject/Weapons/BaseWeapon.h"
#include "AimTrainingProject/Targets/BaseTarget.h"

DEFINE_LOG_CATEGORY_STATIC(LogReactionGameMode, All, All);

void AReactionGameMode::StartPlay()
{
    Super::StartPlay();
    ABaseWeapon* PlayerWeapon = GetPlayerWeapon();
    TimerDelay();
    if (PlayerWeapon)
    {
        PlayerWeapon->OnHit.AddUObject(this, &AReactionGameMode::TimerDelay);
        PlayerWeapon->OnHit.AddUObject(this, &AReactionGameMode::OnTargetHit);
    }
}

void AReactionGameMode::RoundTimerUpdate()
{
    const auto TimerRate = GetWorldTimerManager().GetTimerRate(RoundTimerHandle);
    RoundCountDown -= TimerRate;
    if (RoundCountDown <= 0 && RandomTarget->GetCondition() != true)
    {
        GameOver();
        GetWorldTimerManager().ClearTimer(RoundTimerHandle);
    }
}



void AReactionGameMode::TimerDelay()
{
    float RandomDelay = FMath::RandRange(0.5f, 5.f);
    GetWorldTimerManager().SetTimer(TargetActivationDelay, this, &AReactionGameMode::DelayedTargetActivation, RandomDelay, false);
}

void AReactionGameMode::DelayedTargetActivation()
{
    ActivateRandomTarget();
    GetWorldTimerManager().SetTimer(ReactionTimer, this, &AReactionGameMode::ReactionTimeCounter, 0.001f, true);
}

void AReactionGameMode::OnTargetHit()
{
    const auto PlayerController = GetPlayerController();
    const auto PlayerState = Cast<AReactionPlayerState>(PlayerController->PlayerState);
    if (!PlayerState) return;
    PlayerState->AddHitsNum();
    PlayerState->AddReactionTime(ReactionTime);
    GetWorldTimerManager().ClearTimer(ReactionTimer);
    ReactionTime = 0;
}


