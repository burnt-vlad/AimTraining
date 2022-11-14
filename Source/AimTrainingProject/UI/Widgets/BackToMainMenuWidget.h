// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BackToMainMenuWidget.generated.h"

class UButton;

UCLASS()
class AIMTRAININGPROJECT_API UBackToMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		UButton* BackToMainMenuButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnBackToMainMenu();
};
