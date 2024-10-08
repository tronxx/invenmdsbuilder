object Frame_datosrensmay: TFrame_datosrensmay
  Left = 0
  Top = 0
  Width = 760
  Height = 63
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 14
    Width = 33
    Height = 13
    Caption = 'C�digo'
  end
  object lbl_canti: TLabel
    Left = 377
    Top = 14
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object lbl_folio: TLabel
    Left = 10
    Top = 36
    Width = 27
    Height = 13
    Caption = 'Folios'
  end
  object lbl_serie: TLabel
    Left = 256
    Top = 38
    Width = 24
    Height = 13
    Caption = 'Serie'
  end
  object edt_codigo: TEdit
    Left = 42
    Top = 9
    Width = 118
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object edt_canti: TdxCurrencyEdit
    Left = 423
    Top = 10
    Width = 52
    TabOrder = 1
    OnExit = edt_cantiExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object edt_folios: TdxEdit
    Left = 42
    Top = 32
    Width = 118
    TabOrder = 2
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object lst_series: TListBox
    Left = 287
    Top = 34
    Width = 189
    Height = 21
    ItemHeight = 13
    TabOrder = 3
  end
  object dbedt_descriinven: TDBEdit
    Left = 162
    Top = 9
    Width = 176
    Height = 21
    TabStop = False
    DataField = 'descri'
    DataSource = dts_inven
    TabOrder = 4
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, linea, tipo, costos, coston, piva'
      'from inven where codigo = :CODIGO and cia = :CIA'
      ' ')
    Left = 487
    Top = 6
    ParamData = <
      item
        DataType = ftString
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
    Left = 519
    Top = 6
  end
  object qry_PuntoVta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from PtoVta where  cia= :Cia order by clave')
    Left = 552
    Top = 6
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
    Left = 584
    Top = 6
  end
  object dts_vendedor: TDataSource
    AutoEdit = False
    DataSet = qry_vendedor
    Left = 625
    Top = 6
  end
  object qry_vendedor: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre'
      'from vendedor'
      'order by codigo')
    Left = 656
    Top = 6
  end
  object dts_poblacion: TDataSource
    AutoEdit = False
    DataSet = qry_Poblacion
    Left = 656
    Top = 38
  end
  object qry_Poblacion: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select numero, nombre from poblacs order by nombre')
    Left = 624
    Top = 38
  end
  object qry_ultfol: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select min(folio) as ultfol, count(*) as exist'
      'from movart'
      'where codigo = :CODIGO and  almac = :ALM and salio <> '#39'S'#39' '
      'and fecha <= :FECHA and cia = :CIA')
    Left = 696
    Top = 38
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
    Left = 724
    Top = 36
  end
  object uqry_folsel: TUpdateSQL
    Left = 726
    Top = 6
  end
end
