
void extraButtonsCommands2()  {
  
  // Check if buttons has been pressed down. This is a byte where each bit represents a button-down press:
  uint8_t buttonDownPress = extraButtons.buttonDownAll();

  // B1: "BARS"
  if (extraButtons.isButtonIn(1, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.setPreviewInputVideoSource(0, 1000);
  }
  extraButtons.setButtonColor(1, AtemSwitcher.getProgramInputVideoSource(0)==1000 ? 2 : (AtemSwitcher.getPreviewInputVideoSource(0)==1000 ? 3 : 5));  // Sets color of button to AMBER (2) if in AUX1 BUS mode. Otherwise color "5" which is dimmed yellow
  
  // B2: "COL1"
  if (extraButtons.isButtonIn(2, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.setPreviewInputVideoSource(0, 2001);
  }
  extraButtons.setButtonColor(2, AtemSwitcher.getProgramInputVideoSource(0)==2001 ? 2 : (AtemSwitcher.getPreviewInputVideoSource(0)==2001 ? 3 : 5));  // Sets color of button to AMBER (2) if in AUX1 BUS mode. Otherwise color "5" which is dimmed yellow

  // B3: "COL2"
  if (extraButtons.isButtonIn(3, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.setPreviewInputVideoSource(0, 2002);
  }
  extraButtons.setButtonColor(3, AtemSwitcher.getProgramInputVideoSource(0)==2002 ? 2 : (AtemSwitcher.getPreviewInputVideoSource(0)==2002 ? 3 : 5));  // Sets color of button to AMBER (2) if in AUX1 BUS mode. Otherwise color "5" which is dimmed yellow
 
  // B5: "Key1"
  if (extraButtons.isButtonIn(5, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.setKeyerOnAirEnabled(0, 1,!AtemSwitcher.getKeyerOnAirEnabled(0, 1));  // Toggle upstream keyer 1 by sending the opposite value of the current value.
  }
  extraButtons.setButtonColor(5, AtemSwitcher.getKeyerOnAirEnabled(0, 1) ? 2 : 5);  // Sets color of button to RED (2) if upstream keyer 4 is active. Otherwise color "5" which is dimmed yellow

  // B4: "Black"
  if (extraButtons.isButtonIn(4, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.setPreviewInputVideoSource(0, 0);
  }
  extraButtons.setButtonColor(4, AtemSwitcher.getProgramInputVideoSource(0)==0 ? 2 : (AtemSwitcher.getPreviewInputVideoSource(0)==0 ? 3 : 5));
  
  // B6: "Fade To Black"
  if (extraButtons.isButtonIn(6, buttonDownPress))  {   // Executes button command if pressed:
    AtemSwitcher.performFadeToBlackME(0) ;
  }
  if (AtemSwitcher.getFadeToBlackStateFullyBlack(0))  {  // Setting button color. This is a more complex example which includes blinking during execution:
    if (AtemSwitcher.getFadeToBlackRate(0)>0 && (AtemSwitcher.getFadeToBlackStateFramesRemaining(0)!=AtemSwitcher.getFadeToBlackRate(0)))  {  // It's important to test if fadeToBlack time is more than zero because it's the kind of state from the ATEM which is usually not captured during initialization. Hopefull this will be solved in the future.
        // Blinking with AMBER color if Fade To Black is executing:
      if ((unsigned long)millis() & B10000000)  {
        extraButtons.setButtonColor(6, 4);  
      } 
      else {
        extraButtons.setButtonColor(6, 5); 
      }
    } 
    else {
      extraButtons.setButtonColor(6, 2);  // Sets color of button to RED (2) if Fade To Black is activated
    }
  } 
  else {
    extraButtons.setButtonColor(6, 5);  // Dimmed background if no fade to black
  }

  // B7: "MEDIA1 BUS"
  if (extraButtons.isButtonIn(7, buttonDownPress))  {   // Executes button command if pressed:
    BUSselect = BUSselect==10 ? 0 : 10;
  }
  extraButtons.setButtonColor(7, BUSselect==10 ? 2 : 5);  // Sets color of button to AMBER (2) if in AUX1 BUS mode. Otherwise color "5" which is dimmed yellow

  // B8: "MEDIA2 BUS"
  if (extraButtons.isButtonIn(8, buttonDownPress))  {   // Executes button command if pressed:
    BUSselect = BUSselect==11 ? 0 : 11;
  }
  extraButtons.setButtonColor(8, BUSselect==11 ? 2 : 5);  // Sets color of button to AMBER (2) if in AUX1 BUS mode. Otherwise color "5" which is dimmed yellow

}
