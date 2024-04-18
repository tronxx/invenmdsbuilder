object Frame_datosmantsubproy: TFrame_datosmantsubproy
  Left = 0
  Top = 0
  Width = 446
  Height = 69
  TabOrder = 0
  object Label2: TLabel
    Left = 17
    Top = 21
    Width = 21
    Height = 13
    Caption = 'Tipo'
  end
  object Label1: TLabel
    Left = 193
    Top = 21
    Width = 47
    Height = 13
    Caption = 'Zona Acu'
  end
  object Label3: TLabel
    Left = 295
    Top = 22
    Width = 74
    Height = 13
    Caption = 'Punto de Venta'
  end
  object edt_acu: TdxEdit
    Left = 244
    Top = 18
    Width = 39
    TabOrder = 1
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object edt_ptv: TdxEdit
    Left = 373
    Top = 19
    Width = 64
    TabOrder = 2
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object cmb_tipo: TComboBox
    Left = 43
    Top = 18
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 0
    Items.Strings = (
      'C Costo   Ventas Tradicional'
      'V Importe Ventas Tradicional'
      'F Costo   Ventas Fonacot'
      'E Importe Ventas Fonacot'
      'I Costo   Ventas FIDE'
      'D Importe Ventas FIDE'
      'L Costo   Ventas Celular'
      'M Costo   Ventas IMEVI'
      'N Importe Ventas IMEVI')
  end
end
