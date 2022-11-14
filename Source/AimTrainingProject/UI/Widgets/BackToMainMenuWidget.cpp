// Aim Training Game. Fedosov Vladislav


#include "BackToMainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UBackToMainMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (BackToMainMenuButton)
	{
		BackToMainMenuButton->OnClicked.AddDynamic(this, &UBackToMainMenuWidget::OnBackToMainMenu);
	}
}

void UBackToMainMenuWidget::OnBackToMainMenu()
{
	if (!GetWorld()) return;
	UGameplayStatics::OpenLevel(this, "MainMenuLevel");
}