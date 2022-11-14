// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "BaseHUD.h"
#include "ReactionHUD.generated.h"

UCLASS()
class AIMTRAININGPROJECT_API AReactionHUD : public ABaseHUD
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
};
