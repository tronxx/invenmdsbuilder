object frmSelecciondb: TfrmSelecciondb
  Left = 310
  Top = 286
  Width = 320
  Height = 178
  Caption = 'Seleccion Base Datos'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object RzBorder1: TRzBorder
    Left = 8
    Top = 8
    Width = 289
    Height = 83
  end
  object RzLabel1: TRzLabel
    Left = 33
    Top = 18
    Width = 250
    Height = 20
    Caption = 'Seleccione La Base de Trabajo'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    FrameSides = []
    TextStyle = tsNormal
  end
  object cmbBasedatos: TRzComboBox
    Left = 80
    Top = 45
    Width = 145
    Height = 28
    Style = csDropDownList
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    FrameColor = clTeal
    FrameFlat = True
    FrameFlatStyle = fsFlat
    FrameFocusStyle = fsButtonDown
    FrameVisible = True
    ItemHeight = 20
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 0
    Items.Strings = (
      'LOCAL'
      'LINUX')
  end
  object btnAceptar: TRzBitBtn
    Left = 43
    Top = 104
    Width = 100
    Height = 35
    FrameFlat = True
    Caption = '&Aceptar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = btnAceptarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00666666666666
      66666666666666666666666666666666666666666666666666666666AC666666
      66666666F86666666666666A22C666666666666F88866666666666A2222C6666
      666666F88888666666666A222222C66666666F888888866666666A22CA222C66
      66666F888F88886666666A2C66A222C666666F8866F8888666666AC6666A222C
      66666F86666F8888666666666666A222C66666666666F8888666666666666A22
      2C66666666666F8888666666666666A222C66666666666F8888666666666666A
      22C666666666666F8886666666666666A2C6666666666666F886666666666666
      6AC66666666666666F8666666666666666666666666666666666}
    NumGlyphs = 2
  end
  object btnCerrar: TRzBitBtn
    Left = 171
    Top = 104
    Width = 100
    Height = 35
    FrameFlat = True
    Caption = '&Cerrar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = btnCerrarClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      0400000000000001000000000000000000001000000010000000000000000000
      80000080000000808000800000008000800080800000C0C0C000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0060FF00FF0088
      008868FF88FF88778877FF00FF00FF008800FF88FF88FF88778800FF00FF0007
      008888FF88FF8887887700000000770780008888888877878888666666070007
      8806666666878887888666666600000788066666668888878886666666088807
      8806666666888887888666666608880788066666668888878886660000000807
      0806668888888887F8866609999908078806668FFFFF88878886609999908807
      880668FFFFF888878886609099088807880668F8FF8888878886600090088807
      88066888F8888887888666600608888078066668868888887886666666088888
      0706666666888888878666666600000000066666668888888886}
    NumGlyphs = 2
  end
end
