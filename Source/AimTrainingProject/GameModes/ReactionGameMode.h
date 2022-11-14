// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "AimTrainingProject/GameModes/BaseGameMode.h"
#include "ReactionGameMode.generated.h"

class ABaseWeapon;
class AReactionPlayerState;
class ABaseTarget;

UCLASS()
class AIMTRAININGPROJECT_API AReactionGameMode : public ABaseGameMode
{
	GENERATED_BODY()
public:
	float GetReactionTime();

protected:
	virtual void StartPlay() override;
	virtual void RoundTimerUpdate() override;
private:
	FTimerHandle TargetActivationDelay;
	FTimerHandle ReactionTimer;
	float ReactionTime = 0;

	void ReactionTimeCounter() { ReactionTime += 0.001f; UE_LOG(LogTemp, Error, TEXT("Time: %f"), ReactionTime); };
	void TimerDelay();
	void DelayedTargetActivation();
	void OnTargetHit();


	AReactionPlayerState* ReactionPlayerState;
};
