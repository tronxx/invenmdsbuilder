object Frame_datosmantgpoinv: TFrame_datosmantgpoinv
  Left = 0
  Top = 0
  Width = 646
  Height = 93
  TabOrder = 0
  object Label1: TLabel
    Left = 31
    Top = 20
    Width = 29
    Height = 13
    Caption = '&Grupo'
  end
  object Label2: TLabel
    Left = 208
    Top = 19
    Width = 56
    Height = 13
    Caption = '&Descripción'
  end
  object lbl_codsat: TLabel
    Left = 7
    Top = 44
    Width = 52
    Height = 13
    Caption = 'Codigo.Sat'
    Visible = False
  end
  object edt_ptovta: TEdit
    Left = 72
    Top = 15
    Width = 121
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 14
    TabOrder = 0
    OnKeyDown = edt_ptovtaKeyDown
  end
  object edt_nombre: TEdit
    Left = 271
    Top = 15
    Width = 274
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 30
    TabOrder = 1
  end
  object chk_imprime: TCheckBox
    Left = 560
    Top = 18
    Width = 69
    Height = 17
    Alignment = taLeftJustify
    Caption = '&Imprimible'
    TabOrder = 2
  end
  object lkcmb_codsat: TDBLookupComboBox
    Left = 72
    Top = 40
    Width = 193
    Height = 21
    KeyField = 'CODIGO'
    ListSource = dts_catprodsat
    TabOrder = 3
    Visible = False
  end
  object dbedt_codsat: TDBEdit
    Left = 271
    Top = 39
    Width = 274
    Height = 21
    DataField = 'DESCRI'
    DataSource = dts_catprodsat
    TabOrder = 4
    Visible = False
  end
  object qry_catprodsat: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_catprodsat '
      'where status = '#39'A'#39
      'order by codigo, descri')
    Left = 288
    Top = 48
  end
  object dts_catprodsat: TDataSource
    DataSet = qry_catprodsat
    Left = 320
    Top = 48
  end
end
