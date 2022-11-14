// Aim Training Game. Fedosov Vladislav

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuitGameWidget.generated.h"

class UButton;

UCLASS()
class AIMTRAININGPROJECT_API UQuitGameWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
		UButton* QuitGameButton;

	virtual void NativeOnInitialized() override;

private:
	UFUNCTION()
		void OnQuitGame();
};
