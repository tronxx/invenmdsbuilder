object Frame_datoscaptraspagregaren: TFrame_datoscaptraspagregaren
  Left = 0
  Top = 0
  Width = 737
  Height = 96
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 22
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label11: TLabel
    Left = 6
    Top = 45
    Width = 34
    Height = 13
    Caption = 'Recibe'
  end
  object Label12: TLabel
    Left = 377
    Top = 22
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object Label9: TLabel
    Left = 384
    Top = 42
    Width = 35
    Height = 13
    Caption = 'Serie(s)'
  end
  object Label1: TLabel
    Left = 497
    Top = 22
    Width = 22
    Height = 13
    Caption = 'Folio'
    FocusControl = edt_canti
  end
  object edt_codigo: TEdit
    Left = 40
    Top = 18
    Width = 113
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object lkcmb_ptovta: TDBLookupComboBox
    Left = 42
    Top = 41
    Width = 64
    Height = 21
    KeyField = 'CLAVE'
    ListField = 'CLAVE'
    ListSource = dts_puntovta
    TabOrder = 3
  end
  object DBEdit6: TDBEdit
    Left = 108
    Top = 41
    Width = 230
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_puntovta
    TabOrder = 4
  end
  object edt_canti: TdxCurrencyEdit
    Left = 423
    Top = 18
    Width = 52
    TabOrder = 1
    OnExit = edt_cantiExit
    OnKeyDown = edt_cantiKeyDown
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object lst_series: TComboBox
    Left = 423
    Top = 41
    Width = 170
    Height = 21
    ItemHeight = 13
    TabOrder = 5
  end
  object edt_folios: TdxEdit
    Left = 524
    Top = 18
    Width = 90
    TabOrder = 2
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object DBEdit1descri: TDBEdit
    Left = 155
    Top = 18
    Width = 183
    Height = 21
    TabStop = False
    DataField = 'descri'
    DataSource = dts_inven
    TabOrder = 7
  end
  object Button1: TButton
    Left = 595
    Top = 41
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 6
    OnClick = Button1Click
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      'from inven where codigo = :CODIGO and cia = :CIA order by codigo')
    Left = 55
    Top = 65
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 87
    Top = 65
  end
  object qry_PuntoVta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from almacen where  cia= :Cia order by clav' +
        'e')
    Left = 120
    Top = 65
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_puntovta: TDataSource
    AutoEdit = False
    DataSet = qry_PuntoVta
    Left = 152
    Top = 65
  end
  object qry_ultfol: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select min(folio) as ultfol, count(*) as exist'
      'from movart'
      'where codigo = :CODIGO and  almac = :ALM and salio <> '#39'S'#39' '
      'and fecha <= :FECHA and cia = :CIA')
    Left = 279
    Top = 65
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_folsel: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codigo, b.almac, b.costo, b.modent, '
      'b.folio, b.serie, b.fecha,'
      'b.entcan, b.fecentori, facpro, b.prove'
      'from inven a join movart b on a.codigo = b.codigo'
      'where a.codigo = '#39'x'#39' and salio = '#39'N'#39' and salio = '#39'S'#39)
    UpdateObject = uqry_folsel
    Left = 420
    Top = 60
  end
  object uqry_folsel: TUpdateSQL
    Left = 454
    Top = 62
  end
end
