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
	uint8_t bgColor = 0;

	gfx_Begin(gfx_8bpp);
	gfx_Blit(gfx_screen);
	gfx_FillScreen(bgColor);
    gfx_SetDrawBuffer();
	gfx_SetColor(0xE0);
	
	gfx_SetTextFGColor(0x1E);
	gfx_SetTextScale(2, 2);
	gfx_PrintStringXY("Calculator", 103, 20);
    gfx_PrintStringXY("Street", 103, 55);
	gfx_PrintStringXY("Racing", 103, 80);
    gfx_SetColor(0x10);
    gfx_PrintStringXY("III", 110, 120);
    gfx_SetColor(0x00);
	gfx_SetTextScale(1, 1);
	gfx_PrintStringXY("Press any key", 80, 150);
	gfx_PrintStringXY("oxiti8", 200, 200);
	gfx_BlitBuffer();
	while(!kb_AnyKey());

		uint8_t selected_option = 0;
			
		bool key = false;
		bgColor = 0x20;
		gfx_FillScreen(bgColor);
		gfx_SetTextScale(1, 1);
		gfx_PrintStringXY("Go Race", 20, 50);
		gfx_PrintStringXY("Something 2", 20, 60);
		gfx_PrintStringXY("Also", 20, 70);
		gfx_PrintStringXY("yes", 20, 80);
		gfx_PrintStringXY("more words", 20, 90);
		gfx_PrintStringXY("Not a Car", 20, 100);
		gfx_PrintStringXY("Quit", 20, 110);
		gfx_BlitBuffer();
		gfx_SetColor(bgColor);
		while(!key) {
			kb_Scan();
			key = kb_Data[1] == kb_2nd;
			gfx_FillRectangle(10, 50 + selected_option*10, 10, 10);
			
			if(kb_Data[7] & kb_Up) {
				selected_option--;
				if(selected_option == 255) selected_option = 6;
			}
			if(kb_Data[7] & kb_Down) {
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

    /* Draw to the buffer to avoid rendering artifacts */
    gfx_SetDrawBuffer();

    gfx_End();

    return 0;
}