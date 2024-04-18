object Frame_datosmarca: TFrame_datosmarca
  Left = 0
  Top = 0
  Width = 479
  Height = 105
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 479
    Height = 105
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object lbl_codigo: TLabel
      Left = 6
      Top = 22
      Width = 33
      Height = 13
      Caption = 'Código'
    end
    object lbl_nombre: TLabel
      Left = 103
      Top = 21
      Width = 56
      Height = 13
      Caption = 'Descripción'
      FocusControl = edt_nombre
    end
    object lbl_estado: TLabel
      Left = 112
      Top = 48
      Width = 48
      Height = 13
      Caption = 'lbl_estado'
      Visible = False
    end
    object lbl_status: TLabel
      Left = 7
      Top = 71
      Width = 30
      Height = 13
      Caption = 'Status'
      Visible = False
    end
    object lbl_fecbaj: TLabel
      Left = 137
      Top = 69
      Width = 30
      Height = 13
      Caption = 'Fecha'
      Visible = False
    end
    object edt_codigo: TEdit
      Left = 43
      Top = 19
      Width = 54
      Height = 21
      CharCase = ecUpperCase
      MaxLength = 4
      TabOrder = 0
    end
    object edt_nombre: TdxEdit
      Left = 168
      Top = 19
      Width = 280
      TabOrder = 1
      CharCase = ecUpperCase
      MaxLength = 70
      StoredValues = 2
    end
    object lkcmb_estados: TDBLookupComboBox
      Left = 168
      Top = 43
      Width = 280
      Height = 21
      ListSource = dts_estados
      TabOrder = 2
      Visible = False
    end
    object cmb_status: TComboBox
      Left = 44
      Top = 67
      Width = 53
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 3
      Visible = False
      OnChange = cmb_statusChange
      Items.Strings = (
        'Activo'
        'Baja')
    end
    object date_fecbaj: TDateTimePicker
      Left = 168
      Top = 67
      Width = 205
      Height = 21
      CalAlignment = dtaLeft
      Date = 42672.4564317477
      Time = 42672.4564317477
      DateFormat = dfShort
      DateMode = dmComboBox
      Kind = dtkDate
      ParseInput = False
      TabOrder = 4
      Visible = False
    end
  end
  object dts_estados: TDataSource
    AutoEdit = False
    DataSet = qry_estados
    Left = 358
    Top = 56
  end
  object qry_estados: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from ctestados order by estado')
    Left = 312
    Top = 56
  end
end
