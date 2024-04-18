object Frame_datosmantotiposctes: TFrame_datosmantotiposctes
  Left = 0
  Top = 0
  Width = 762
  Height = 44
  TabOrder = 0
  object Label1: TLabel
    Left = 19
    Top = 11
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object lbl_nombre: TLabel
    Left = 117
    Top = 11
    Width = 40
    Height = 13
    Caption = '&Nombre '
    FocusControl = edt_nombre
  end
  object lbl_tipocartera: TLabel
    Left = 452
    Top = 13
    Width = 58
    Height = 13
    Caption = 'Tipo Cartera'
  end
  object lbl_remate: TLabel
    Left = 632
    Top = 13
    Width = 37
    Height = 13
    Caption = 'Remate'
  end
  object edt_ptovta: TEdit
    Left = 56
    Top = 9
    Width = 49
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 2
    TabOrder = 0
  end
  object edt_nombre: TdxEdit
    Left = 160
    Top = 9
    Width = 281
    TabOrder = 1
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object lkcmb_ptovta: TDBLookupComboBox
    Left = 512
    Top = 9
    Width = 105
    Height = 21
    DropDownWidth = 200
    KeyField = 'DESCRI'
    ListField = 'DESCRI'
    ListSource = dts_tipocar
    TabOrder = 2
  end
  object cmb_remate: TComboBox
    Left = 674
    Top = 9
    Width = 54
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Items.Strings = (
      'N'
      'R')
  end
  object qry_tipocar: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from car_tipocar')
    Left = 413
    Top = 32
  end
  object dts_tipocar: TDataSource
    DataSet = qry_tipocar
    Left = 444
    Top = 32
  end
end
