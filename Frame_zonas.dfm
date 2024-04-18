object Frme_zonas: TFrme_zonas
  Left = 0
  Top = 0
  Width = 471
  Height = 47
  TabOrder = 0
  object lbl_codigo: TLabel
    Left = 19
    Top = 16
    Width = 33
    Height = 13
    Caption = '&Código'
    FocusControl = edt_ptovta
  end
  object lbl_nombre: TLabel
    Left = 132
    Top = 16
    Width = 40
    Height = 13
    Caption = '&Nombre '
    FocusControl = edt_nombre
  end
  object edt_ptovta: TdxCurrencyEdit
    Left = 64
    Top = 12
    Width = 41
    TabOrder = 0
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object edt_nombre: TdxEdit
    Left = 176
    Top = 12
    Width = 280
    TabOrder = 1
    CharCase = ecUpperCase
    MaxLength = 30
    StoredValues = 2
  end
end
