#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

#include <graphx.h>
#include <keypadc.h>
#include <fileioc.h>

void begin(void);
void end(void);
bool step(void);
void draw(void);

int main(void)
{
    bool partial_redraw = false;
	uint8_t  bgColor

	gfx_Begin(gfx_8bpp);
	gfx_Blit(gfx_screen);
	gfx_FillScreen(bgColor);
    gfx_SetDrawBuffer();
	gfx_SetColor(0xE0);
	
	gfx_SetTextFGColor(0x02);
	gfx_SetTextScale(2, 2);
	gfx_PrintStringXY("Calculator", 103, 20);
    delay(300);
    gfx_PrintStringXY("Street", 103, 50);
    delay(300);
	gfx_PrintStringXY("Racing", 103, 80);
    delay(300);
    gfx_SetColor(0x10);
    gfx_PrintStringXY("III", 103, 80);
    gfx_SetColor(0x00);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Press Enter", 80, 120);
	gfx_PrintStringXY("oxiti8", 78, 140);
	gfx_BlitBuffer();
	
	delay(1000);


			uint8_t selected_option = 0;
			
			gfx_FillScreen(bgColor);
			gfx_SetTextScale(1, 1);
			gfx_PrintStringXY("Keymapping", 20, 50);
			gfx_PrintStringXY("Cycles per frame -", 20, 60);
			gfx_PrintStringXY("Quirks -", 20, 70);
			gfx_PrintStringXY("Foreground color -", 20, 80);
			gfx_PrintStringXY("Background color -", 20, 90);
			gfx_PrintStringXY("Resume", 20, 100);
			gfx_PrintStringXY("Quit game", 20, 110);
			gfx_BlitBuffer();
			gfx_SetColor(bgColor);
			while(!kb_Data[1] & kb_2nd) {
				kb_Scan();
				
				gfx_FillRectangle(10, 50 + selected_option*10, 10, 10);
				
				if(kb_Up) {
					selected_option--;
					if(selected_option == 255) selected_option = 6;
				}
				if(kb_Down) {
					selected_option++;
					if(selected_option == 7) selected_option = 0;
				}
				
				gfx_PrintStringXY(">", 10, 50 + selected_option*10);
				
				if(selected_option == 0) {
				}
				
				if(selected_option == 1) {
				}
				
				if(selected_option == 2) {

				}
				
				if(selected_option == 3) {

				}

				if(selected_option == 4) {
				}
				
				if(selected_option == 5) {
				}
				
				if(selected_option == 6) {

				}		

				gfx_BlitBuffer();
				delay(100);
			}
		}

    /* Draw to the buffer to avoid rendering artifacts */
    gfx_SetDrawBuffer();

    /* No rendering allowed in step! */
    /* End graphics drawing */
    gfx_End();

    return 0;