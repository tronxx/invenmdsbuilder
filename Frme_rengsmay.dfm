object Frame_rengsmay: TFrame_rengsmay
  Left = 0
  Top = 0
  Width = 760
  Height = 133
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 14
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label11: TLabel
    Left = 13
    Top = 37
    Width = 26
    Height = 13
    Caption = 'P.Vta'
  end
  object Label2: TLabel
    Left = 7
    Top = 62
    Width = 32
    Height = 13
    Caption = 'Cliente'
    FocusControl = edt_nombre
  end
  object Label15: TLabel
    Left = 6
    Top = 86
    Width = 33
    Height = 13
    Caption = 'Ciudad'
  end
  object Label12: TLabel
    Left = 377
    Top = 14
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object Label13: TLabel
    Left = 521
    Top = 14
    Width = 34
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Status*'
    ParentShowHint = False
    ShowHint = True
  end
  object Label5: TLabel
    Left = 373
    Top = 38
    Width = 46
    Height = 13
    Caption = 'Vendedor'
  end
  object Label10: TLabel
    Left = 392
    Top = 62
    Width = 27
    Height = 13
    Caption = 'Folios'
  end
  object Label9: TLabel
    Left = 392
    Top = 86
    Width = 24
    Height = 13
    Caption = 'Serie'
  end
  object lbl_prvta: TLabel
    Left = 358
    Top = 108
    Width = 61
    Height = 13
    Caption = 'Precio Venta'
    Visible = False
  end
  object lbl_crdocont: TLabel
    Left = 497
    Top = 110
    Width = 49
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Cred/Cont'
    ParentShowHint = False
    ShowHint = True
  end
  object lbl_tipago: TLabel
    Left = 225
    Top = 110
    Width = 49
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Tipo Pago'
    ParentShowHint = False
    ShowHint = True
    Visible = False
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
  object edt_nombre: TdxEdit
    Left = 42
    Top = 58
    Width = 297
    TabOrder = 7
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object lkcmb_poblac: TDBLookupComboBox
    Left = 42
    Top = 82
    Width = 298
    Height = 21
    KeyField = 'NUMERO'
    ListField = 'NOMBRE'
    ListSource = dts_poblacion
    TabOrder = 8
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
  object cmb_status: TComboBox
    Left = 562
    Top = 10
    Width = 50
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 2
    Items.Strings = (
      'S'
      'N')
  end
  object DBEdit5: TDBEdit
    Left = 476
    Top = 33
    Width = 136
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_vendedor
    TabOrder = 6
  end
  object lkcmb_vendedr: TDBLookupComboBox
    Left = 424
    Top = 33
    Width = 52
    Height = 21
    DropDownWidth = 200
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_vendedor
    TabOrder = 5
  end
  object edt_folios: TdxEdit
    Left = 424
    Top = 58
    Width = 187
    TabOrder = 10
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object lst_series: TListBox
    Left = 423
    Top = 82
    Width = 189
    Height = 21
    ItemHeight = 13
    TabOrder = 11
  end
  object edt_prvta: TdxCurrencyEdit
    Left = 423
    Top = 107
    Width = 65
    TabOrder = 12
    Visible = False
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 0
  end
  object cmb_credcont: TComboBox
    Left = 552
    Top = 106
    Width = 60
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 9
    Items.Strings = (
      'Contado'
      'Credito')
  end
  object DBEdit1: TDBEdit
    Left = 162
    Top = 9
    Width = 176
    Height = 21
    TabStop = False
    DataField = 'descri'
    DataSource = dts_inven
    TabOrder = 13
  end
  object cmb_tipago: TComboBox
    Left = 280
    Top = 106
    Width = 60
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 14
    Visible = False
    Items.Strings = (
      'Efectivo'
      'Caja Ahorro'
      'ACL')
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      'from inven where codigo = :CODIGO and cia = :CIA')
    Left = 15
    Top = 102
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
    Left = 47
    Top = 102
  end
  object qry_PuntoVta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from PtoVta where  cia= :Cia order by clave')
    Left = 80
    Top = 102
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
    Left = 112
    Top = 102
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
    Left = 692
    Top = 100
  end
  object uqry_folsel: TUpdateSQL
    Left = 694
    Top = 70
  end
end
