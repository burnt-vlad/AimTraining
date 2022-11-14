// Aim Training Game. Fedosov Vladislav

#include "BaseGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AimTrainingProject/Player/BasePlayer.h"
#include "AimTrainingProject/Weapons/BaseWeapon.h"
#include "AimTrainingProject/Targets/BaseTarget.h"
#include "AimTrainingProject/Weapons/WeaponComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGameMode, All, All);

void ABaseGameMode::StartPlay()
{
    Super::StartPlay();
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseTarget::StaticClass(), TargetsInWorld);
    NumberOfTargets = TargetsInWorld.Num();
    SetMatchState(EMatchState::InProgress);
    StartRound();
}

int32 ABaseGameMode::GetRandomizeTargetIndex()
{
    int32 RandomizedTargetIndex = FMath::RandRange(0, (TargetsInWorld.Num() - 1));
    if (RandomizedTargetIndex == TargetIndex)
    {
        return GetRandomizeTargetIndex();
    }
    else
    {
        return TargetIndex = RandomizedTargetIndex;
    }
}

void ABaseGameMode::ActivateRandomTarget()
{
    int32 RandomizedTargetIndex = GetRandomizeTargetIndex();
    RandomTarget = Cast<ABaseTarget>(TargetsInWorld[RandomizedTargetIndex]);
    RandomTarget->ActivateTarget();
}

void ABaseGameMode::StartRound()
{
    GetWorldTimerManager().SetTimer(RoundTimerHandle, this, &ABaseGameMode::RoundTimerUpdate, 1.0f, true);
    RoundCountDown = RoundTime;
}

void ABaseGameMode::RoundTimerUpdate()
{
    const auto TimerRate = GetWorldTimerManager().GetTimerRate(RoundTimerHandle);
    RoundCountDown -= TimerRate;
    if (RoundCountDown <= 0)
    {
        GameOver();
        GetWorldTimerManager().ClearTimer(RoundTimerHandle);
    }
}

APlayerController* ABaseGameMode::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return nullptr;
    const auto PlayerController = Player->GetController<APlayerController>();
    if (!PlayerController) return nullptr;
    return PlayerController;
}

UWeaponComponent* ABaseGameMode::GetWeaponComponent()
{
    const auto Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return nullptr;
    const auto WeaponComponent = Cast<UWeaponComponent>(Player->GetComponentByClass(UWeaponComponent::StaticClass()));
    if (!WeaponComponent) return nullptr;
    return WeaponComponent;
}

ABaseWeapon* ABaseGameMode::GetPlayerWeapon()
{
    UWeaponComponent* WeaponComponent = GetWeaponComponent();
    if (!WeaponComponent) return nullptr;
    ABaseWeapon* Weapon = WeaponComponent->GetWeapon();
    if (!Weapon) return nullptr;
    return Weapon;
}

void ABaseGameMode::SetMatchState(EMatchState State)
{
    if (MatchState == State) return;
    MatchState = State;
    OnMatchStateChanged.Broadcast(MatchState);
}

void ABaseGameMode::GameOver()
{
    const auto Player = Cast<ACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player) return;
    const auto Weapon = GetPlayerWeapon();
    if (!Weapon) return;
    Player->Destroy();
    Weapon->Destroy();
    SetMatchState(EMatchState::GameOver);
}

bool ABaseGameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (PauseSet)
    {
        SetMatchState(EMatchState::Pause);
    }
    return PauseSet;
}

bool ABaseGameMode::ClearPause()
{
    const auto PauseCleared = Super::ClearPause();
    if (PauseCleared)
    {
        SetMatchState(EMatchState::InProgress);
    }
    return PauseCleared;
}
