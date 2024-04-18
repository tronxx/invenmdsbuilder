object Frame_datoscapcancelagrega: TFrame_datoscapcancelagrega
  Left = 0
  Top = 0
  Width = 717
  Height = 133
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 11
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label12: TLabel
    Left = 377
    Top = 12
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object Label13: TLabel
    Left = 469
    Top = 12
    Width = 34
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Status*'
    ParentShowHint = False
    ShowHint = True
  end
  object Label10: TLabel
    Left = 577
    Top = 11
    Width = 22
    Height = 13
    Caption = 'Folio'
  end
  object Label11: TLabel
    Left = 13
    Top = 34
    Width = 26
    Height = 13
    Caption = 'P.Vta'
  end
  object Label9: TLabel
    Left = 394
    Top = 34
    Width = 24
    Height = 13
    Caption = 'Serie'
  end
  object Label2: TLabel
    Left = 7
    Top = 59
    Width = 32
    Height = 13
    Caption = 'Cliente'
    FocusControl = edt_nombre
  end
  object Label7: TLabel
    Left = 354
    Top = 59
    Width = 66
    Height = 13
    Caption = 'Status Cancel'
  end
  object Label6: TLabel
    Left = 477
    Top = 59
    Width = 27
    Height = 13
    Caption = 'Costo'
  end
  object Label15: TLabel
    Left = 6
    Top = 83
    Width = 33
    Height = 13
    Caption = 'Ciudad'
  end
  object Label5: TLabel
    Left = 373
    Top = 82
    Width = 46
    Height = 13
    Caption = 'Vendedor'
  end
  object lbl_prvta: TLabel
    Left = 359
    Top = 105
    Width = 61
    Height = 13
    Caption = 'Precio Venta'
    Visible = False
  end
  object lbl_crdocont: TLabel
    Left = 519
    Top = 105
    Width = 49
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Cred/Cont'
    ParentShowHint = False
    ShowHint = True
  end
  object edt_codigo: TEdit
    Left = 42
    Top = 7
    Width = 113
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object edt_descri: TDBEdit
    Left = 155
    Top = 7
    Width = 183
    Height = 21
    TabStop = False
    DataField = 'DESCRI'
    DataSource = dts_inven
    TabOrder = 1
  end
  object edt_canti: TdxCurrencyEdit
    Left = 423
    Top = 7
    Width = 26
    TabOrder = 2
    OnExit = edt_cantiExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object cmb_status: TComboBox
    Left = 510
    Top = 7
    Width = 40
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
    OnExit = cmb_statusExit
    Items.Strings = (
      'S'
      'N')
  end
  object edt_folios: TdxEdit
    Left = 608
    Top = 7
    Width = 25
    TabOrder = 4
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object lkcmb_ptovta: TDBLookupComboBox
    Left = 42
    Top = 30
    Width = 64
    Height = 21
    KeyField = 'CLAVE'
    ListField = 'CLAVE'
    ListSource = dts_puntovta
    TabOrder = 5
  end
  object DBEdit6: TDBEdit
    Left = 108
    Top = 30
    Width = 230
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_puntovta
    TabOrder = 6
  end
  object edt_nombre: TdxEdit
    Left = 42
    Top = 55
    Width = 297
    TabOrder = 9
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object cmb_entcan: TComboBox
    Left = 424
    Top = 55
    Width = 40
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 10
    Items.Strings = (
      'S'
      'N')
  end
  object lkcmb_poblac: TDBLookupComboBox
    Left = 42
    Top = 79
    Width = 298
    Height = 21
    KeyField = 'NUMERO'
    ListField = 'NOMBRE'
    ListSource = dts_poblacion
    TabOrder = 12
  end
  object lkcmb_vendedr: TDBLookupComboBox
    Left = 424
    Top = 79
    Width = 52
    Height = 21
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_vendedor
    TabOrder = 13
  end
  object DBEdit5: TDBEdit
    Left = 476
    Top = 79
    Width = 157
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_vendedor
    TabOrder = 14
  end
  object lst_series: TComboBox
    Left = 423
    Top = 30
    Width = 188
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 7
  end
  object edt_costou: TdxCurrencyEdit
    Left = 512
    Top = 54
    Width = 121
    TabOrder = 11
  end
  object edt_prvta: TdxCurrencyEdit
    Left = 424
    Top = 102
    Width = 80
    TabOrder = 15
    Visible = False
  end
  object Button1: TButton
    Left = 612
    Top = 30
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 8
    OnClick = Button1Click
  end
  object cmb_credcont: TComboBox
    Left = 574
    Top = 102
    Width = 60
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 16
    Items.Strings = (
      'Contado'
      'Credito')
  end
  object qry_puntovta: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from PtoVta where  cia= :Cia order by clave')
    Left = 137
    Top = 99
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_puntovta: TDataSource
    AutoEdit = False
    DataSet = qry_puntovta
    Left = 169
    Top = 99
  end
  object qry_poblacion: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select numero, nombre from poblacs order by nombre')
    Left = 72
    Top = 99
  end
  object dts_poblacion: TDataSource
    AutoEdit = False
    DataSet = qry_poblacion
    Left = 105
    Top = 99
  end
  object qry_vendedor: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre'
      'from vendedor'
      'order by codigo')
    Left = 10
    Top = 100
  end
  object dts_vendedor: TDataSource
    AutoEdit = False
    DataSet = qry_vendedor
    Left = 41
    Top = 100
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      'from inven where codigo = :CODIGO and cia = :CIA order by codigo')
    Left = 262
    Top = 99
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
    Left = 294
    Top = 100
  end
  object qry_folsigent: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select ultfol from exist'
      'where '
      'codigo = :CODIGO and  alm = :ALM and cia = :CIA')
    Left = 655
    Top = 7
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_ultfol: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select ultfol '
      'from exist'
      'where codigo = :CODIGO and  alm = :ALM and cia = :CIA')
    Left = 687
    Top = 7
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
    Left = 648
    Top = 42
  end
  object uqry_folsel: TUpdateSQL
    Left = 649
    Top = 77
  end
end
