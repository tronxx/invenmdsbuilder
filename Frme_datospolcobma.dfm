object Frame_datospolcobma: TFrame_datospolcobma
  Left = 0
  Top = 0
  Width = 696
  Height = 68
  TabOrder = 0
  object Label4: TLabel
    Left = 290
    Top = 9
    Width = 22
    Height = 13
    Caption = 'Folio'
  end
  object Label3: TLabel
    Left = 29
    Top = 11
    Width = 17
    Height = 13
    Caption = 'Alm'
  end
  object Label5: TLabel
    Left = 2
    Top = 33
    Width = 46
    Height = 13
    Caption = 'Concepto'
  end
  object Label1: TLabel
    Left = 374
    Top = 9
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object Label6: TLabel
    Left = 506
    Top = 9
    Width = 36
    Height = 13
    Caption = 'Usuario'
  end
  object Label7: TLabel
    Left = 509
    Top = 34
    Width = 33
    Height = 13
    Caption = 'Estado'
  end
  object Label2: TLabel
    Left = 382
    Top = 35
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object edt_folio: TdxCurrencyEdit
    Left = 318
    Top = 7
    Width = 49
    TabOrder = 1
    DisplayFormat = '0;-0'
    StoredValues = 0
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 53
    Top = 7
    Width = 57
    Height = 21
    DropDownWidth = 200
    KeyField = 'CLAVE'
    ListField = 'CLAVE; NOMBRE'
    ListSource = dts_almacen
    TabOrder = 0
    OnExit = lkcmb_almacenExit
  end
  object edt_concepto: TEdit
    Left = 53
    Top = 32
    Width = 313
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object date_fecha: TDateTimePicker
    Left = 409
    Top = 7
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 38944.6100131944
    Time = 38944.6100131944
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object edt_usuario: TEdit
    Left = 545
    Top = 8
    Width = 90
    Height = 21
    TabStop = False
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object dbedt_status: TDBEdit
    Left = 545
    Top = 31
    Width = 30
    Height = 21
    TabStop = False
    DataField = 'STATUS'
    TabOrder = 5
  end
  object dbedt_total: TdxDBCurrencyEdit
    Left = 409
    Top = 32
    Width = 90
    TabOrder = 6
    TabStop = False
  end
  object DBEdit1: TDBEdit
    Left = 112
    Top = 7
    Width = 173
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_almacen
    TabOrder = 7
  end
  object dts_almacen: TDataSource
    DataSet = qry_almacen
    Left = 160
    Top = 32
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from almacen where cia = :Cia order by clav' +
        'e')
    Left = 208
    Top = 32
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
end
