object Form_mantmayo: TForm_mantmayo
  Left = 260
  Top = 103
  Width = 669
  Height = 590
  Caption = 'Mantenimiento de Mayoristas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 653
    Height = 53
    ButtonHeight = 49
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 0
    object SpeedButton6: TSpeedButton
      Left = 0
      Top = 2
      Width = 49
      Height = 49
      Action = nuevo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF0000FF
        FF0000FFFF00FF00FF007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF007B7B
        7B007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF00FF00FF00FF00FF00FF00
        FF0000FFFF000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF0000FFFF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF00FF00FF00FF00FF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF0000FFFF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000FFFF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF0000FF
        FF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00}
      Layout = blGlyphTop
    end
    object SpeedButton5: TSpeedButton
      Left = 49
      Top = 2
      Width = 49
      Height = 49
      Action = modifica
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        0000FF00FF000000000000000000000000000000000000000000FFFFFF00FFFF
        FF0000000000FFFFFF000000000000000000FFFFFF0000000000FFFF00000000
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
        00000000000000FFFF0000000000FFFFFF00FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000000000000000000000000000000000000000000000
        000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        00000000000000FFFF00FFFFFF0000FFFF00000000000000000000FFFF000000
        0000FFFFFF00FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFFFF000000
        000000000000FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000FFFF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00000000000000FF0000000000FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton4: TSpeedButton
      Left = 98
      Top = 2
      Width = 49
      Height = 49
      Action = borra
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF007B7B7B007B7B
        7B007B7B7B007B7B7B007B7B7B007B7B7B007B7B7B00FF00FF007B7B7B00FF00
        FF00FF00FF000000FF000000FF000000FF00FF00FF007B7B7B00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000084840000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00
        FF00FF00FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF000000000000FF
        FF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000000000FFFFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF0000FFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000000000000000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000FFFF000000000000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00000000000000000000FFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FFFF000000
        000000FFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        000000000000FFFF0000FFFF0000FFFF00000000000000FFFF00FFFFFF0000FF
        FF00FFFFFF000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        00000000000000000000FFFF0000FFFF0000FFFF000000000000000000000000
        0000000000000000000000FFFF0000000000FF00FF00FF00FF00000000000000
        0000000000000000000000000000FFFF000000000000FF00FF00FF00FF00FF00
        FF00FF00FF0000000000BDBDBD0000000000FF00FF00FF00FF00FF00FF000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton1: TSpeedButton
      Left = 147
      Top = 2
      Width = 49
      Height = 49
      Action = WindowClose1
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000000084000000840000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF000000000000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000FFFF00000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object ToolButton2: TToolButton
      Left = 196
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object SpeedButton10: TSpeedButton
      Left = 204
      Top = 2
      Width = 49
      Height = 49
      Action = primero
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000000000000000
        000000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton8: TSpeedButton
      Left = 253
      Top = 2
      Width = 49
      Height = 49
      Action = anterior
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000FF00FF00FF00
        FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton9: TSpeedButton
      Left = 302
      Top = 2
      Width = 49
      Height = 49
      Action = siguiente
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF000000000000000000FF00FF00FF00FF00000000000000
        FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton7: TSpeedButton
      Left = 351
      Top = 2
      Width = 49
      Height = 49
      Action = ultimo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF0000000000000000000000000000000000000000000000
        FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000}
      Layout = blGlyphTop
    end
  end
  object dbgrd_mayoris: TdxDBGrid
    Left = 0
    Top = 53
    Width = 653
    Height = 498
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    OnDblClick = dbgrd_mayorisDblClick
    OnKeyDown = dbgrd_mayorisKeyDown
    DataSource = dts_mayoris
    Filter.Criteria = {00000000}
    OptionsBehavior = [edgoAutoSearch, edgoAutoSort, edgoDragScroll, edgoEditing, edgoEnterShowEditor, edgoImmediateEditor, edgoTabThrough, edgoVertThrough]
    OptionsDB = [edgoCancelOnExit, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks, edgoUseLocate]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    OnCustomDrawCell = dbgrd_mayorisCustomDrawCell
    object dbgrd_mayorisCODIGO: TdxDBGridMaskColumn
      Caption = 'Codigo'
      Width = 35
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_mayorisNOMBRE: TdxDBGridMaskColumn
      Caption = 'Nombre'
      Width = 120
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE'
    end
    object dbgrd_mayorisContNombre: TdxDBGridMaskColumn
      Caption = 'Cont.Nombre'
      Width = 50
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMBRE2'
    end
    object dbgrd_mayorisDIREC: TdxDBGridMaskColumn
      Caption = 'Direccion'
      Width = 98
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DIREC'
    end
    object dbgrd_mayorisDESCRI: TdxDBGridMaskColumn
      Caption = 'Tipo'
      Width = 23
      BandIndex = 0
      RowIndex = 0
      FieldName = 'descri'
    end
    object dbgrd_mayorisCIU: TdxDBGridMaskColumn
      Caption = 'Ciudad'
      Width = 35
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CIU'
    end
    object dbgrd_mayorisRFC: TdxDBGridMaskColumn
      Width = 82
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RFC'
    end
    object dbgrd_mayorisTEL: TdxDBGridMaskColumn
      Caption = 'Telefono'
      Width = 27
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TEL'
    end
    object dbgrd_mayorisPDSC: TdxDBGridMaskColumn
      Caption = 'Descuento'
      Width = 34
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PDSC'
    end
    object dbgrd_mayorisNOMPAG1: TdxDBGridMaskColumn
      Caption = 'Nombre Pag.'
      Width = 39
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NOMPAG1'
    end
    object dbgrd_mayorisDIRPAG1: TdxDBGridMaskColumn
      Caption = 'Direcci�n '
      Width = 29
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DIRPAG1'
    end
    object dbgrd_mayorisDIRPAG2: TdxDBGridMaskColumn
      Caption = 'Seg. Direcci�n'
      Width = 30
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DIRPAG2'
    end
    object dbgrd_mayorisCIUPAG: TdxDBGridMaskColumn
      Caption = 'Ciudad'
      Width = 22
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CIUPAG'
    end
    object dbgrd_mayorisColumn13: TdxDBGridMaskColumn
      Caption = 'Status'
      Width = 33
      BandIndex = 0
      RowIndex = 0
      FieldName = 'STATUS'
    end
  end
  object qry_mayoris: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      
        'codigo, nombre, direc, ciu, rfc, tel, cargos, abonos, compraanu,' +
        ' comprames,'
      
        'pdsc, ultmov, status, a.cia, nompag1, nompag2, dirpag1, dirpag2,' +
        ' ciupag, nombre2,'
      'a.tipo, b.descri'
      
        'from mayoris a left outer join inv_tipomayoris b on a.tipo = b.i' +
        'dtipomay'
      'where a.cia = :CIA'
      'order by codigo')
    UpdateObject = uqry_mayoris
    Left = 473
    Top = 165
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_mayoris: TUpdateSQL
    ModifySQL.Strings = (
      'update mayoris'
      'set'
      '  CODIGO = :CODIGO,'
      '  NOMBRE = :NOMBRE,'
      '  DIREC = :DIREC,'
      '  CIU = :CIU,'
      '  RFC = :RFC,'
      '  TEL = :TEL,'
      '  CARGOS = :CARGOS,'
      '  ABONOS = :ABONOS,'
      '  COMPRAANU = :COMPRAANU,'
      '  COMPRAMES = :COMPRAMES,'
      '  PDSC = :PDSC,'
      '  ULTMOV = :ULTMOV,'
      '  STATUS = :STATUS,'
      '  CIA = :CIA,'
      '  NOMPAG1 = :NOMPAG1,'
      '  NOMPAG2 = :NOMPAG2,'
      '  DIRPAG1 = :DIRPAG1,'
      '  DIRPAG2 = :DIRPAG2,'
      '  CIUPAG = :CIUPAG,'
      '  NOMBRE2 = :NOMBRE2,'
      '  TIPO = :TIPO'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into mayoris'
      
        '  (CODIGO, NOMBRE, DIREC, CIU, RFC, TEL, CARGOS, ABONOS, COMPRAA' +
        'NU, '
      'COMPRAMES, '
      
        '   PDSC, ULTMOV, STATUS, CIA, NOMPAG1, NOMPAG2, DIRPAG1, DIRPAG2' +
        ', '
      'CIUPAG, '
      '   NOMBRE2, TIPO)'
      'values'
      
        '  (:CODIGO, :NOMBRE, :DIREC, :CIU, :RFC, :TEL, :CARGOS, :ABONOS,' +
        ' '
      ':COMPRAANU, '
      
        '   :COMPRAMES, :PDSC, :ULTMOV, :STATUS, :CIA, :NOMPAG1, :NOMPAG2' +
        ', '
      ':DIRPAG1, '
      '   :DIRPAG2, :CIUPAG, :NOMBRE2, :TIPO)')
    DeleteSQL.Strings = (
      'delete from mayoris'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    Left = 503
    Top = 165
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 532
    Top = 165
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = nuevoExecute
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
      OnExecute = modificaExecute
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
      OnExecute = borraExecute
    end
    object grabar: TAction
      Caption = 'Grabar'
      Enabled = False
      ImageIndex = 9
      ShortCut = 16455
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      Enabled = False
      ImageIndex = 11
      ShortCut = 16460
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = '&Salir'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'Primero'
      Hint = 'Selecciona al Primer Mayorista'
      ImageIndex = 5
      ShortCut = 49232
      OnExecute = primeroExecute
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona al Anterior Mayorista'
      ImageIndex = 6
      ShortCut = 49217
      OnExecute = anteriorExecute
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona al Siguiente Mayorista'
      ImageIndex = 8
      ShortCut = 49235
      OnExecute = siguienteExecute
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona al Ultimo Mayorista'
      ImageIndex = 7
      ShortCut = 49237
      OnExecute = ultimoExecute
    end
    object agrega_tel: TAction
      Caption = 'Agregar'
      ImageIndex = 28
    end
    object elimina_tel: TAction
      Caption = 'Eliminar'
      ImageIndex = 2
    end
    object exportar: TAction
      Caption = 'Exportar a...'
      ImageIndex = 19
      OnExecute = exportarExecute
    end
  end
  object qry_ciudades: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from poblacs'
      'order by nombre ')
    Left = 504
    Top = 88
  end
  object dts_ciudades: TDataSource
    DataSet = qry_ciudades
    Left = 504
    Top = 120
  end
  object qry_ciupag: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select nombre, numero from poblacs'
      'order by nombre ')
    Left = 472
    Top = 88
  end
  object dts_ciupag: TDataSource
    DataSet = qry_ciupag
    Left = 472
    Top = 120
  end
  object qry_tipostel: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idtipotel, descri from may_tipostel')
    Left = 565
    Top = 88
  end
  object PopupMenu1: TPopupMenu
    Left = 563
    Top = 164
    object Eliminar1: TMenuItem
      Action = elimina_tel
    end
    object Modifica1: TMenuItem
      Action = modifica
    end
    object Nuevo1: TMenuItem
      Action = nuevo
    end
    object Borra1: TMenuItem
      Action = borra
    end
    object Exportara1: TMenuItem
      Action = exportar
    end
  end
  object qry_mostmayo: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  * from mayoris where codigo = :CODIGO and cia = :CIA'
      ' ')
    Left = 473
    Top = 202
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_mayoris: TDataSource
    AutoEdit = False
    DataSet = qry_mayoris
    Left = 503
    Top = 202
  end
  object qry_datospago: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ', a.iddato2, a.cia,'
      'b.concep as tipopago, c.concep as numcta'
      'from may_relac a join inv_conceps b on a.iddato1 = b.idconcep'
      'join inv_conceps c on a.iddato2 = c.idconcep'
      'where a.mayoris = :MAYORIS and idmayoris = -1 and a.cia = :CIA'
      'order by a.idtiporel')
    UpdateObject = uqry_datospago
    Left = 474
    Top = 236
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_datospago: TUpdateSQL
    ModifySQL.Strings = (
      'update may_relac'
      'set'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2,'
      '  CIA = :CIA'
      'where'
      '  IDRELAC = :OLD_IDRELAC'
      ' ')
    InsertSQL.Strings = (
      'insert into may_relac'
      
        '  (IDRELAC, IDMAYORIS, MAYORIS, IDTIPOREL, IDDATO1, IDDATO2, CIA' +
        ')'
      'values'
      
        '  (:IDRELAC, :IDMAYORIS, :MAYORIS, :IDTIPOREL, :IDDATO1, :IDDATO' +
        '2, :CIA)')
    DeleteSQL.Strings = (
      'delete from may_relac'
      'where'
      '  IDRELAC = :OLD_IDRELAC'
      ' ')
    Left = 472
    Top = 264
  end
  object qry_telefonos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idrelac, a.idmayoris, a.mayoris, a.idtiporel, a.iddato1' +
        ', a.iddato2, a.cia,'
      'b.descri as tipotel, c.telfax'
      'from may_relac a join may_tipostel b on a.iddato1 = b.idtipotel'
      'join telfax c on a.iddato2 = c.idtel'
      
        'where a.mayoris = :MAYORIS and a.idtiporel = :IDTIPOREL and a.ci' +
        'a = :CIA')
    UpdateObject = uqry_telefonos
    Left = 507
    Top = 237
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'IDTIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_telefonos: TUpdateSQL
    ModifySQL.Strings = (
      'update may_relac'
      'set'
      '  IDRELAC = :IDRELAC,'
      '  IDMAYORIS = :IDMAYORIS,'
      '  MAYORIS = :MAYORIS,'
      '  IDTIPOREL = :IDTIPOREL,'
      '  IDDATO1 = :IDDATO1,'
      '  IDDATO2 = :IDDATO2,'
      '  CIA = :CIA'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    InsertSQL.Strings = (
      'insert into may_relac'
      
        '  (IDRELAC, IDMAYORIS, MAYORIS, IDTIPOREL, IDDATO1, IDDATO2, CIA' +
        ')'
      'values'
      
        '  (:IDRELAC, :IDMAYORIS, :MAYORIS, :IDTIPOREL, :IDDATO1, :IDDATO' +
        '2, :CIA)')
    DeleteSQL.Strings = (
      'delete from may_relac'
      'where'
      '  IDRELAC = :OLD_IDRELAC')
    Left = 505
    Top = 265
  end
end
