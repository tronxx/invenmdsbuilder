object Frame_datosubivta: TFrame_datosubivta
  Left = 0
  Top = 0
  Width = 588
  Height = 287
  TabOrder = 0
  object Label1: TLabel
    Left = 16
    Top = 43
    Width = 41
    Height = 13
    Caption = 'Almacén'
  end
  object Label2: TLabel
    Left = 16
    Top = 67
    Width = 74
    Height = 13
    Caption = 'Punto de Venta'
  end
  object Label3: TLabel
    Left = 16
    Top = 91
    Width = 55
    Height = 13
    Caption = 'Zona Inven'
  end
  object Label4: TLabel
    Left = 16
    Top = 115
    Width = 92
    Height = 13
    Caption = 'Venta/Cancelación'
  end
  object Label5: TLabel
    Left = 16
    Top = 139
    Width = 62
    Height = 13
    Caption = 'Zona x P.Vta'
  end
  object Label6: TLabel
    Left = 16
    Top = 163
    Width = 32
    Height = 13
    Caption = 'P.Vta2'
  end
  object Label7: TLabel
    Left = 176
    Top = 139
    Width = 393
    Height = 13
    Caption = 
      'Cuando un Punto de Venta debe Sumar las Ventas con Otro p:ejempl' +
      'o FNMT y MT'
  end
  object Label8: TLabel
    Left = 176
    Top = 163
    Width = 393
    Height = 13
    Caption = 
      'Cuando un Punto de Venta debe Sumar las Ventas con Otro p:ejempl' +
      'o FNMT y MT'
  end
  object Label9: TLabel
    Left = 16
    Top = 187
    Width = 69
    Height = 13
    Caption = 'Zona Art.Desp'
  end
  object Label10: TLabel
    Left = 176
    Top = 187
    Width = 265
    Height = 13
    Caption = 'La zona a la que debe sumarse lo artículos desplazados'
  end
  object Label11: TLabel
    Left = 16
    Top = 211
    Width = 69
    Height = 13
    Caption = 'Zona de P.Vta'
  end
  object Label12: TLabel
    Left = 176
    Top = 211
    Width = 304
    Height = 13
    Caption = 'La zona del Punto de Venta sin importar el almacén del cual sale'
  end
  object Label13: TLabel
    Left = 16
    Top = 235
    Width = 77
    Height = 13
    Caption = 'Zona de Cartera'
  end
  object Label14: TLabel
    Left = 178
    Top = 235
    Width = 183
    Height = 13
    Caption = 'La zona del Punto de Venta en cartera'
  end
  object Label15: TLabel
    Left = 16
    Top = 259
    Width = 94
    Height = 13
    Caption = 'Subzona de Cartera'
  end
  object Label16: TLabel
    Left = 178
    Top = 259
    Width = 202
    Height = 13
    Caption = 'La Subzona del Punto de Venta en cartera'
  end
  object Label17: TLabel
    Left = 179
    Top = 43
    Width = 139
    Height = 13
    Caption = 'Almacén del Kardex de salida'
  end
  object Label18: TLabel
    Left = 179
    Top = 67
    Width = 74
    Height = 13
    Caption = 'Punto de Venta'
  end
  object Label19: TLabel
    Left = 179
    Top = 91
    Width = 160
    Height = 13
    Caption = 'Zona de Inven donde se acumula'
  end
  object Label20: TLabel
    Left = 179
    Top = 115
    Width = 231
    Height = 13
    Caption = 'Esta es una ubicación de Venta o Cancelación ?'
  end
  object Label21: TLabel
    Left = 16
    Top = 19
    Width = 48
    Height = 13
    Caption = 'Ubicación'
  end
  object Label22: TLabel
    Left = 179
    Top = 19
    Width = 141
    Height = 13
    Caption = 'Ubicación a la que Pertenece'
  end
  object edt_almac: TEdit
    Left = 120
    Top = 40
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 1
  end
  object edt_ptovta: TEdit
    Left = 120
    Top = 64
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 2
  end
  object edt_zonainv: TEdit
    Left = 120
    Top = 88
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object edt_zonaptvta: TEdit
    Left = 120
    Top = 136
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 5
  end
  object edt_ptvta2: TEdit
    Left = 120
    Top = 160
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 6
  end
  object edt_zonartdesp: TEdit
    Left = 120
    Top = 184
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 7
  end
  object edt_zonapvta2: TEdit
    Left = 120
    Top = 208
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 8
  end
  object edt_zonacar: TEdit
    Left = 120
    Top = 232
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 9
  end
  object edt_subzoncar: TEdit
    Left = 120
    Top = 256
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 10
  end
  object cmb_voc: TComboBox
    Left = 120
    Top = 112
    Width = 50
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    Items.Strings = (
      'Venta'
      'Cancelación')
  end
  object edt_ubica: TEdit
    Left = 120
    Top = 16
    Width = 50
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 0
  end
end
