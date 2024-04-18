object Frame_datosmantovnd: TFrame_datosmantovnd
  Left = 0
  Top = 0
  Width = 708
  Height = 62
  TabOrder = 0
  object Label1: TLabel
    Left = 19
    Top = 11
    Width = 33
    Height = 13
    Caption = 'Codigo'
  end
  object Label2: TLabel
    Left = 117
    Top = 11
    Width = 40
    Height = 13
    Caption = '&Nombre '
    FocusControl = edt_nombre
  end
  object Label3: TLabel
    Left = 461
    Top = 13
    Width = 25
    Height = 13
    Caption = 'Zona'
  end
  object lbs_status: TLabel
    Left = 126
    Top = 36
    Width = 30
    Height = 13
    Caption = 'Status'
  end
  object lbl_fecbaj: TLabel
    Left = 456
    Top = 37
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object edt_cajera: TEdit
    Left = 56
    Top = 9
    Width = 49
    Height = 21
    CharCase = ecUpperCase
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
    Left = 488
    Top = 9
    Width = 65
    Height = 21
    DropDownWidth = 200
    KeyField = 'ZONA'
    ListField = 'ZONA; NOMBRE'
    ListSource = dts_ptovta
    TabOrder = 2
  end
  object DBEdit1: TDBEdit
    Left = 553
    Top = 9
    Width = 140
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_ptovta
    TabOrder = 3
  end
  object cmb_status: TComboBox
    Left = 160
    Top = 32
    Width = 145
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 4
    OnChange = cmb_statusChange
    Items.Strings = (
      'Activo'
      'Baja')
  end
  object date_fecbaj: TDateTimePicker
    Left = 489
    Top = 32
    Width = 205
    Height = 21
    CalAlignment = dtaLeft
    Date = 42672.4564317477
    Time = 42672.4564317477
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 5
  end
  object qry_ptovta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by zona')
    Left = 577
    Top = 32
  end
  object dts_ptovta: TDataSource
    DataSet = qry_ptovta
    Left = 608
    Top = 32
  end
end
