// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AimTrainingProject/AimTrainingGameInstance.h"
#include "BaseHUD.generated.h"

class UUserWidget;

UCLASS()
class AIMTRAININGPROJECT_API ABaseHUD : public AHUD
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget>PlayerHUDWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget>PauseWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		TSubclassOf<UUserWidget>GameOverWidgetClass;
	virtual void BeginPlay() override;

	UPROPERTY()
		TMap<EMatchState, UUserWidget*> GameWidgets;
	UPROPERTY()
		UUserWidget* CurrentWidget = nullptr;

	void OnMatchStateChanged(EMatchState State);
};
