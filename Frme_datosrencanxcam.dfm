object Frame_datosrencanxcam: TFrame_datosrencanxcam
  Left = 0
  Top = 0
  Width = 622
  Height = 146
  TabOrder = 0
  object Label8: TLabel
    Left = 6
    Top = 22
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label6: TLabel
    Left = 349
    Top = 21
    Width = 71
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Entrada/Salida'
    ParentShowHint = False
    ShowHint = True
  end
  object Label7: TLabel
    Left = 491
    Top = 21
    Width = 51
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Cancelado'
    ParentShowHint = False
    ShowHint = True
  end
  object Label11: TLabel
    Left = 13
    Top = 45
    Width = 26
    Height = 13
    Caption = 'P.Vta'
  end
  object Label12: TLabel
    Left = 377
    Top = 46
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object Label13: TLabel
    Left = 507
    Top = 46
    Width = 34
    Height = 13
    Hint = 'El status es S=Status 1, N=Status 2'
    Caption = 'Status*'
    ParentShowHint = False
    ShowHint = True
  end
  object lbl_prvta: TLabel
    Left = 499
    Top = 67
    Width = 41
    Height = 13
    Caption = 'Costo U.'
  end
  object Label10: TLabel
    Left = 392
    Top = 70
    Width = 27
    Height = 13
    Caption = 'Folios'
  end
  object Label5: TLabel
    Left = 373
    Top = 117
    Width = 46
    Height = 13
    Caption = 'Vendedor'
  end
  object Label2: TLabel
    Left = 7
    Top = 70
    Width = 32
    Height = 13
    Caption = 'Cliente'
    FocusControl = edt_nombre
  end
  object Label1: TLabel
    Left = 7
    Top = 94
    Width = 33
    Height = 13
    Caption = 'Ciudad'
    FocusControl = edt_nombre
  end
  object Label3: TLabel
    Left = 391
    Top = 94
    Width = 29
    Height = 13
    Caption = 'Series'
    FocusControl = edt_nombre
  end
  object edt_codigo: TEdit
    Left = 43
    Top = 18
    Width = 113
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object DBEdit4: TDBEdit
    Left = 158
    Top = 18
    Width = 180
    Height = 21
    TabStop = False
    DataField = 'DESCRI'
    DataSource = dts_inven
    TabOrder = 1
  end
  object cmb_entosal: TComboBox
    Left = 423
    Top = 18
    Width = 52
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 2
    Items.Strings = (
      'E'
      'S')
  end
  object cmb_statcan: TComboBox
    Left = 548
    Top = 18
    Width = 65
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
    Items.Strings = (
      'N'
      'S')
  end
  object lkcmb_ptovta: TDBLookupComboBox
    Left = 42
    Top = 42
    Width = 64
    Height = 21
    KeyField = 'CLAVE'
    ListField = 'CLAVE'
    ListSource = dts_puntovta
    TabOrder = 4
  end
  object DBEdit6: TDBEdit
    Left = 108
    Top = 42
    Width = 230
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_puntovta
    TabOrder = 5
  end
  object edt_canti: TdxCurrencyEdit
    Left = 423
    Top = 42
    Width = 52
    TabOrder = 6
    OnExit = edt_cantiExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object cmb_status: TComboBox
    Left = 548
    Top = 42
    Width = 65
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 7
    Items.Strings = (
      'S'
      'N')
  end
  object lst_series: TComboBox
    Left = 424
    Top = 89
    Width = 160
    Height = 21
    ItemHeight = 13
    TabOrder = 11
  end
  object edt_folios: TdxEdit
    Left = 424
    Top = 65
    Width = 49
    TabOrder = 14
    TabStop = False
    CharCase = ecUpperCase
    MaxLength = 15
    ReadOnly = True
    StoredValues = 66
  end
  object lkcmb_vendedr: TDBLookupComboBox
    Left = 424
    Top = 113
    Width = 52
    Height = 21
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_vendedor
    TabOrder = 13
  end
  object DBEdit5: TDBEdit
    Left = 476
    Top = 113
    Width = 136
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_vendedor
    TabOrder = 15
  end
  object lkcmb_poblac: TDBLookupComboBox
    Left = 42
    Top = 89
    Width = 298
    Height = 21
    KeyField = 'NUMERO'
    ListField = 'NOMBRE'
    ListSource = dts_poblacion
    TabOrder = 10
  end
  object edt_nombre: TdxEdit
    Left = 42
    Top = 65
    Width = 296
    TabOrder = 8
    CharCase = ecUpperCase
    MaxLength = 50
    StoredValues = 2
  end
  object edt_costo: TdxCurrencyEdit
    Left = 549
    Top = 65
    Width = 61
    TabOrder = 9
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '$,0.00;-,0.00'
    StoredValues = 1
  end
  object Button1: TButton
    Left = 588
    Top = 89
    Width = 21
    Height = 21
    Caption = '...'
    TabOrder = 12
    OnClick = Button1Click
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      'from inven where codigo = :CODIGO and cia = :CIA order by codigo')
    Left = 40
    Top = 26
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
    Left = 76
    Top = 24
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
  object dts_folsel: TDataSource
    DataSet = qry_folsel
    Left = 344
    Top = 40
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
    Left = 343
    Top = 72
  end
  object uqry_folsel: TUpdateSQL
    Left = 344
    Top = 104
  end
end
