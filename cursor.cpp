//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <memory>       //Подменяем курсор в пямяти

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

  std::auto_ptr<Graphics::TBitmap> bmpMask(new Graphics::TBitmap);
  std::auto_ptr<Graphics::TBitmap> bmpColor(new Graphics::TBitmap);
  std::auto_ptr<TIconInfo> iconInfo(new TIconInfo);

  bmpMask->LoadFromFile("../../c1.bmp");
  bmpColor->LoadFromFile("../../c2.bmp");

  iconInfo->fIcon = false;
  iconInfo->xHotspot = 25;
  iconInfo->yHotspot = 10;
  iconInfo->hbmMask = bmpMask->Handle;
  iconInfo->hbmColor = bmpColor->Handle;

  Screen->Cursors[crCross] = CreateIconIndirect(iconInfo.get());
  Screen->Cursor = crCross;
}
//---------------------------------------------------------------------------
