object Frame_datoscapcancel: TFrame_datoscapcancel
  Left = 0
  Top = 0
  Width = 586
  Height = 58
  TabOrder = 0
  object RzLabel1: TLabel
    Left = 13
    Top = 10
    Width = 44
    Height = 13
    Caption = 'A&lmacén:'
  end
  object Label1: TLabel
    Left = 22
    Top = 34
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label3: TLabel
    Left = 270
    Top = 34
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object RzLabel3: TLabel
    Left = 301
    Top = 9
    Width = 40
    Height = 13
    Caption = '&Número:'
  end
  object RzLabel4: TLabel
    Left = 438
    Top = 12
    Width = 33
    Height = 13
    Caption = '&Fecha:'
  end
  object Label4: TLabel
    Left = 449
    Top = 34
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 66
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
    Left = 116
    Top = 7
    Width = 180
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_almacen
    TabOrder = 1
  end
  object dxDBCurrencyEdit1: TdxDBCurrencyEdit
    Left = 66
    Top = 32
    Width = 121
    TabOrder = 4
    Alignment = taRightJustify
    DataField = 'IMPORTE'
    StoredValues = 1
  end
  object dxDBCurrencyEdit2: TdxDBCurrencyEdit
    Left = 290
    Top = 32
    Width = 121
    TabOrder = 5
    Alignment = taRightJustify
    DataField = 'IVA'
    StoredValues = 1
  end
  object edt_numero: TdxCurrencyEdit
    Left = 346
    Top = 7
    Width = 65
    TabOrder = 2
    DisplayFormat = '0;(0)'
    StoredValues = 0
  end
  object date_fecha: TDateTimePicker
    Left = 478
    Top = 8
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 38601.5553621528
    Time = 38601.5553621528
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
  end
  object dxDBCurrencyEdit3: TdxDBCurrencyEdit
    Left = 478
    Top = 32
    Width = 90
    TabOrder = 6
    Alignment = taRightJustify
    DataField = 'TOTAL'
    StoredValues = 1
  end
  object qry_Almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from Almacen where Cia = :Cia order by clav' +
        'e'
      '')
    Left = 148
    Top = 23
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
    Left = 196
    Top = 23
  end
end
