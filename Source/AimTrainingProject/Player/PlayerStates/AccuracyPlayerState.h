// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AccuracyPlayerState.generated.h"


UCLASS()
class AIMTRAININGPROJECT_API AAccuracyPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	void AddShotsNum() { ++ShotsNum; }
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetShotsNum() const { return ShotsNum; }
	void AddHitsNum() { ++HitsNum; }
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetHitsNum() const { return HitsNum; }
	void PrintStat();

private:
	int32 ShotsNum = 0;
	int32 HitsNum = 0;
};
  