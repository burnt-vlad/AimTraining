// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "AimTrainingProject/GameModes/BaseGameMode.h"
#include "AccuracyGameMode.generated.h"

class ABaseWeapon;

UCLASS()
class AIMTRAININGPROJECT_API AAccuracyGameMode : public ABaseGameMode
{
	GENERATED_BODY()

public:
	AAccuracyGameMode();

protected:
	virtual void StartPlay() override;

private:
	void AddHitsNum();
	void AddShotsNum();
};
