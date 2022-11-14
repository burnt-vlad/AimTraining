// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AimTrainingProject/AimTrainingGameInstance.h"
#include "BaseGameMode.generated.h"

class ABaseTarget;
class UWeaponComponent;
class ABaseWeapon;
class ABaseTarget;

UCLASS()
class AIMTRAININGPROJECT_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	FOnMatchStateChanged OnMatchStateChanged;
	int32 GetRoundCountDown() { return RoundCountDown; }
	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
	virtual bool ClearPause() override;

protected:

	virtual void StartPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "Targets")
		TSubclassOf<ABaseTarget> TargetClass;
	UPROPERTY(EditDefaultsOnly, Category = "Game rules", meta = (ClampMin = "10", ClampMax = "60"))
		int32 RoundTime = 10.f;
	int32 NumberOfTargets;
	ABaseTarget* RandomTarget = nullptr;

	virtual void ActivateRandomTarget();
	UWeaponComponent* GetWeaponComponent();
	ABaseWeapon* GetPlayerWeapon();
	APlayerController* GetPlayerController() const;
	void GameOver();
	void SetMatchState(EMatchState State);
	virtual void RoundTimerUpdate();
	int32 RoundCountDown = 0;
	FTimerHandle RoundTimerHandle;

private:
	TArray<AActor*> TargetsInWorld;
	int32 TargetIndex = 0;
	int32 GetRandomizeTargetIndex();
	EMatchState MatchState = EMatchState::WaitingForTheStart;

	void StartRound();
};
