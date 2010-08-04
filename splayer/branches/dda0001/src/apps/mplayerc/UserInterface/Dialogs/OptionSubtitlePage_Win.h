#ifndef OPTIONSUBTITLEPAGE_WIN_H
#define OPTIONSUBTITLEPAGE_WIN_H

#include "../../resource.h"

class OptionSubtitlePage:
  public WTL::CPropertyPageImpl<OptionSubtitlePage>,
  public WTL::COwnerDraw<OptionSubtitlePage>
{
public:
  enum { IDD = IDD_OPTION_SUBTITLE};

  BEGIN_MSG_MAP(OptionSubtitlePage)
    MSG_WM_INITDIALOG(OnInitDialog)
    MSG_WM_DESTROY(OnDestroy)
    CHAIN_MSG_MAP(COwnerDraw<OptionSubtitlePage>)
  END_MSG_MAP()

  // message handlers
  BOOL OnInitDialog(HWND hwnd, LPARAM lParam);
  void OnDestroy();

  // owner-draw logic for subtitle styles
  void DrawItem(LPDRAWITEMSTRUCT lpdis);
  void MeasureItem(LPMEASUREITEMSTRUCT lpmis);

  // activate/apply handler
  int OnSetActive();
  int OnApply();

private:
  CComboBox m_subtitletype;
  CListBox  m_subtitlestyle;
};

#endif // OPTIONSUBTITLEPAGE_WIN_H