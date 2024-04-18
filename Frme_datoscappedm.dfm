object Frame_datoscappedm: TFrame_datoscappedm
  Left = 0
  Top = 0
  Width = 668
  Height = 103
  TabOrder = 0
  object Label14: TLabel
    Left = 23
    Top = 35
    Width = 32
    Height = 13
    Caption = 'Cliente'
  end
  object Label2: TLabel
    Left = 26
    Top = 58
    Width = 26
    Height = 13
    Caption = 'Plazo'
  end
  object Label5: TLabel
    Left = 220
    Top = 58
    Width = 43
    Height = 13
    Caption = 'Contacto'
  end
  object Label1: TLabel
    Left = 527
    Top = 10
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label3: TLabel
    Left = 544
    Top = 32
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object Label4: TLabel
    Left = 535
    Top = 56
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object Label6: TLabel
    Left = 17
    Top = 11
    Width = 38
    Height = 13
    Caption = 'Per�odo'
  end
  object Label7: TLabel
    Left = 267
    Top = 11
    Width = 37
    Height = 13
    Caption = 'N�mero'
  end
  object Label8: TLabel
    Left = 385
    Top = 11
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 59
    Top = 7
    Width = 56
    Height = 21
    KeyField = 'CLAVE'
    ListField = 'CLAVE; NOMBRE'
    ListSource = dts_almacen
    TabOrder = 0
    OnExit = lkcmb_almacenExit
  end
  object lkcmb_vendedr: TDBLookupComboBox
    Left = 59
    Top = 31
    Width = 56
    Height = 21
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_mayorista
    TabOrder = 3
  end
  object edt_facpro: TEdit
    Left = 59
    Top = 54
    Width = 100
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 30
    TabOrder = 4
  end
  object DBEdit2: TDBEdit
    Left = 115
    Top = 31
    Width = 392
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_mayorista
    TabOrder = 6
  end
  object DBEdit1: TDBEdit
    Left = 115
    Top = 7
    Width = 142
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_almacen
    TabOrder = 7
  end
  object edt_contacto: TEdit
    Left = 268
    Top = 54
    Width = 239
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 30
    TabOrder = 5
  end
  object dbedt_total: TdxDBCurrencyEdit
    Left = 563
    Top = 54
    Width = 90
    TabOrder = 8
    TabStop = False
    Alignment = taRightJustify
    DataField = 'TOTAL'
    StoredValues = 1
  end
  object dbedt_iva: TdxDBCurrencyEdit
    Left = 564
    Top = 31
    Width = 90
    TabOrder = 9
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IVA'
    StoredValues = 1
  end
  object dbedt_importe: TdxDBCurrencyEdit
    Left = 564
    Top = 7
    Width = 90
    TabOrder = 10
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IMPORTE'
    StoredValues = 1
  end
  object date_fecha: TDateTimePicker
    Left = 424
    Top = 8
    Width = 84
    Height = 21
    CalAlignment = dtaLeft
    Date = 40879.5819241898
    Time = 40879.5819241898
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object edt_numero: TdxCurrencyEdit
    Left = 313
    Top = 7
    Width = 60
    TabOrder = 1
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object qry_Almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select letra as clave, cast(anio as varchar(30)) as nombre'
      'from periodoent where anio >= 201001 order by clave'
      ' ')
    Left = 168
    Top = 72
  end
  object dts_almacen: TDataSource
    AutoEdit = False
    DataSet = qry_Almacen
    Left = 200
    Top = 72
  end
  object qry_mayorista: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre, tipo'
      'from mayoris'
      'where cia = :CIA'
      'order by codigo')
    Left = 240
    Top = 72
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_mayorista: TDataSource
    AutoEdit = False
    DataSet = qry_mayorista
    Left = 273
    Top = 74
  end
end
