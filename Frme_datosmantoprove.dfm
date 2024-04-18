object Frame_datosmantoprove: TFrame_datosmantoprove
  Left = 0
  Top = 0
  Width = 508
  Height = 203
  TabOrder = 0
  object Label1: TLabel
    Left = 36
    Top = 22
    Width = 33
    Height = 13
    Caption = '&Código'
  end
  object Label2: TLabel
    Left = 32
    Top = 46
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object Label3: TLabel
    Left = 24
    Top = 69
    Width = 45
    Height = 13
    Caption = 'Dirección'
  end
  object Label4: TLabel
    Left = 27
    Top = 111
    Width = 42
    Height = 13
    Caption = 'Teléfono'
  end
  object Label7: TLabel
    Left = 19
    Top = 91
    Width = 50
    Height = 13
    Caption = 'Población '
  end
  object Label6: TLabel
    Left = 4
    Top = 137
    Width = 65
    Height = 13
    Caption = 'Límite Crédito'
  end
  object Label12: TLabel
    Left = 26
    Top = 157
    Width = 43
    Height = 13
    Caption = 'Contacto'
  end
  object Label5: TLabel
    Left = 289
    Top = 111
    Width = 21
    Height = 13
    Caption = 'RFC'
  end
  object Label8: TLabel
    Left = 274
    Top = 135
    Width = 33
    Height = 13
    Caption = 'Estado'
  end
  object edt_limite: TdxCurrencyEdit
    Left = 74
    Top = 132
    Width = 161
    TabOrder = 6
  end
  object edt_nombre: TEdit
    Left = 74
    Top = 40
    Width = 401
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 1
  end
  object edt_direc: TEdit
    Left = 74
    Top = 63
    Width = 401
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 2
  end
  object edt_tel: TEdit
    Left = 74
    Top = 109
    Width = 161
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object edt_contacto: TEdit
    Left = 74
    Top = 155
    Width = 401
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 7
  end
  object edt_codvnd: TEdit
    Left = 74
    Top = 16
    Width = 56
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 4
    TabOrder = 0
  end
  object edt_ciudad: TEdit
    Left = 74
    Top = 86
    Width = 401
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object edt_rfc: TEdit
    Left = 313
    Top = 109
    Width = 161
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 5
  end
  object cmb_estado: TComboBox
    Left = 313
    Top = 132
    Width = 161
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 8
    Items.Strings = (
      'Alta'
      'Baja')
  end
end
