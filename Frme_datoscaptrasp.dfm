object Frame_datoscaptrasp: TFrame_datoscaptrasp
  Left = 0
  Top = 0
  Width = 598
  Height = 58
  TabOrder = 0
  object lbl_total: TLabel
    Left = 451
    Top = 34
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object lbl_iva: TLabel
    Left = 272
    Top = 34
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object lbl_importe: TLabel
    Left = 24
    Top = 34
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object lbl_alm: TLabel
    Left = 23
    Top = 11
    Width = 41
    Height = 13
    Caption = '&Almacén'
    FocusControl = lkcmb_almacen
  end
  object lbl_numero: TLabel
    Left = 303
    Top = 11
    Width = 37
    Height = 13
    Caption = 'Número'
  end
  object Label6: TLabel
    Left = 438
    Top = 12
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 68
    Top = 7
    Width = 49
    Height = 21
    DropDownWidth = 200
    KeyField = 'CLAVE'
    ListField = 'CLAVE; NOMBRE'
    ListSource = dts_almacen
    TabOrder = 0
    OnExit = lkcmb_almacenExit
  end
  object DBEdit1: TDBEdit
    Left = 118
    Top = 7
    Width = 180
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_almacen
    TabOrder = 6
  end
  object dbedt_total: TdxDBCurrencyEdit
    Left = 480
    Top = 32
    Width = 90
    TabOrder = 5
    TabStop = False
    Alignment = taRightJustify
    DataField = 'TOTAL'
    StoredValues = 1
  end
  object dbedt_iva: TdxDBCurrencyEdit
    Left = 292
    Top = 32
    Width = 121
    TabOrder = 4
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IVA'
    StoredValues = 1
  end
  object dbedt_importe: TdxDBCurrencyEdit
    Left = 68
    Top = 32
    Width = 121
    TabOrder = 3
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IMPORTE'
    StoredValues = 1
  end
  object edt_numero: TdxCurrencyEdit
    Left = 353
    Top = 7
    Width = 60
    TabOrder = 1
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object date_fecha: TDateTimePicker
    Left = 480
    Top = 7
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
    OnExit = date_fechaExit
  end
  object qry_Almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from Almacen where status = '#39'A'#39' and Cia = :' +
        'Cia'
      'order by clave'
      ''
      ' ')
    Left = 188
    Top = 30
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_almacen: TDataSource
    AutoEdit = False
    DataSet = qry_Almacen
    Left = 220
    Top = 30
  end
end
