// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ReactionPlayerState.generated.h"

UCLASS()
class AIMTRAININGPROJECT_API AReactionPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	void AddReactionTime(float Time) { ReactionTime += Time; };
	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetReactionTime() const { return ReactionTime; }
	void AddHitsNum() { ++HitsNum; };
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetHitsNum() const { return HitsNum; }

private:
	float ReactionTime;
	int32 HitsNum;
};
