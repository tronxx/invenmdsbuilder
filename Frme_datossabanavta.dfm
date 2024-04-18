object Frame_datossabanavta: TFrame_datossabanavta
  Left = 0
  Top = 0
  Width = 627
  Height = 70
  TabOrder = 0
  object Label1: TLabel
    Left = 167
    Top = 34
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label3: TLabel
    Left = 327
    Top = 34
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object Label4: TLabel
    Left = 459
    Top = 34
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object Label2: TLabel
    Left = 23
    Top = 10
    Width = 41
    Height = 13
    Caption = 'Almacén'
  end
  object Label5: TLabel
    Left = 307
    Top = 10
    Width = 37
    Height = 13
    Caption = 'Número'
  end
  object Label6: TLabel
    Left = 447
    Top = 10
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object dxDBCurrencyEdit1: TdxDBCurrencyEdit
    Left = 208
    Top = 32
    Width = 90
    TabOrder = 4
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IMPORTE'
    StoredValues = 1
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 68
    Top = 7
    Width = 49
    Height = 21
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
    TabOrder = 3
  end
  object dxDBCurrencyEdit2: TdxDBCurrencyEdit
    Left = 348
    Top = 32
    Width = 90
    TabOrder = 5
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IVA'
    StoredValues = 1
  end
  object dxDBCurrencyEdit3: TdxDBCurrencyEdit
    Left = 488
    Top = 32
    Width = 90
    TabOrder = 6
    TabStop = False
    Alignment = taRightJustify
    DataField = 'TOTAL'
    StoredValues = 1
  end
  object edt_numero: TdxCurrencyEdit
    Left = 348
    Top = 8
    Width = 90
    TabOrder = 1
    DecimalPlaces = 0
    DisplayFormat = '0;-0'
    StoredValues = 0
  end
  object date_fecha: TDateTimePicker
    Left = 488
    Top = 8
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 40555.3599430324
    Time = 40555.3599430324
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 2
  end
  object dts_almacen: TDataSource
    AutoEdit = False
    DataSet = qry_almacen
    Left = 584
    Top = 8
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from Almacen where Cia = :Cia order by clav' +
        'e'
      '')
    Left = 224
    Top = 32
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_conse: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select max(conse) as ultren '
      
        'from renentra where tipo = :TIPO and alm = :ALM and numero = :NU' +
        'MERO and cia = :CIA')
    Left = 424
    Top = 24
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Alm'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
end
