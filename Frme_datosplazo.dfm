object Frame_datosplazo: TFrame_datosplazo
  Left = 0
  Top = 0
  Width = 517
  Height = 189
  TabOrder = 0
  object pnl_pzoxlinea: TPanel
    Left = 0
    Top = -2
    Width = 517
    Height = 75
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 0
    Visible = False
    object Label1: TLabel
      Left = 14
      Top = 16
      Width = 26
      Height = 13
      Caption = 'Linea'
    end
    object lbl_tipoplzo: TLabel
      Left = 14
      Top = 40
      Width = 21
      Height = 13
      Caption = 'Tipo'
    end
    object lkcmb_lineas: TDBLookupComboBox
      Left = 49
      Top = 11
      Width = 64
      Height = 21
      KeyField = 'IDLINEA'
      ListField = 'LINEA'
      ListSource = dts_lineas
      TabOrder = 0
    end
    object DBEdit1: TDBEdit
      Left = 115
      Top = 11
      Width = 260
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_lineas
      TabOrder = 1
    end
    object chk_prioridad: TCheckBox
      Left = 381
      Top = 11
      Width = 132
      Height = 17
      Caption = 'Prioridad sobre Precio'
      TabOrder = 2
      Visible = False
    end
    object lkcmb_tipoplazo: TDBLookupComboBox
      Left = 49
      Top = 34
      Width = 145
      Height = 21
      DropDownWidth = 300
      KeyField = 'idplazo'
      ListField = 'cvepzo'
      ListSource = dts_tipoplazo
      TabOrder = 3
    end
    object dbedt_tipoplazo: TDBEdit
      Left = 195
      Top = 34
      Width = 180
      Height = 21
      DataField = 'descri'
      DataSource = dts_tipoplazo
      TabOrder = 4
    end
  end
  object pnl_pzoxcodigo: TPanel
    Left = 0
    Top = 73
    Width = 517
    Height = 28
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 1
    Visible = False
    object Label4: TLabel
      Left = 11
      Top = 8
      Width = 33
      Height = 13
      Caption = 'Código'
    end
    object edt_codigo: TEdit
      Left = 49
      Top = 4
      Width = 121
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
      OnKeyDown = edt_codigoKeyDown
    end
    object edt_descri: TEdit
      Left = 174
      Top = 3
      Width = 296
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 1
    end
    object lkcmb_codigos: TDBLookupComboBox
      Left = 344
      Top = 0
      Width = 145
      Height = 21
      DropDownWidth = 300
      KeyField = 'CODIGO'
      ListField = 'CODIGO; descri'
      ListSource = dts_buscod
      TabOrder = 2
      Visible = False
      OnExit = lkcmb_codigosExit
      OnKeyDown = lkcmb_codigosKeyDown
    end
  end
  object pnl_pzoxgrupo: TPanel
    Left = 0
    Top = 101
    Width = 517
    Height = 57
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 2
    Visible = False
    object lgl_gpo: TLabel
      Left = 14
      Top = 8
      Width = 29
      Height = 13
      Caption = 'Grupo'
    end
    object lbl_tipo: TLabel
      Left = 235
      Top = 31
      Width = 21
      Height = 13
      Caption = 'Tipo'
      Visible = False
    end
    object lkcmb_grupos: TDBLookupComboBox
      Left = 48
      Top = 3
      Width = 153
      Height = 21
      KeyField = 'IDGRUPO'
      ListField = 'CODIGO'
      ListSource = dts_grupos
      TabOrder = 0
    end
    object dbedt_descri: TDBEdit
      Left = 202
      Top = 3
      Width = 260
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_grupos
      TabOrder = 1
    end
    object chk_prioridadgpo: TCheckBox
      Left = 51
      Top = 27
      Width = 132
      Height = 17
      Caption = 'Prioridad sobre Precio'
      TabOrder = 2
      Visible = False
    end
    object cmb_tipo: TComboBox
      Left = 278
      Top = 26
      Width = 185
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 3
      Visible = False
      Items.Strings = (
        'FILIAL'
        'MAYOREO'
        'PRECIO MAYORISTA X COSTO')
    end
  end
  object pnl_datosprecios: TPanel
    Left = 0
    Top = 158
    Width = 517
    Height = 31
    Align = alBottom
    BevelOuter = bvNone
    TabOrder = 3
    object lbl_precio: TLabel
      Left = 3
      Top = 7
      Width = 94
      Height = 13
      Caption = 'Precio Lista Máximo'
    end
    object lbl_plazo: TLabel
      Left = 251
      Top = 7
      Width = 65
      Height = 13
      Caption = 'Plazo Máximo'
    end
    object edt_plismax: TdxCurrencyEdit
      Left = 105
      Top = 3
      Width = 100
      TabOrder = 0
    end
    object edt_plazomax: TdxCurrencyEdit
      Left = 319
      Top = 3
      Width = 51
      TabOrder = 1
      DisplayFormat = '0;-0'
      StoredValues = 0
    end
  end
  object dts_lineas: TDataSource
    AutoEdit = False
    DataSet = qry_lineas
    Left = 417
    Top = 41
  end
  object qry_lineas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idlinea, linea, descri from inv_lineas'
      'where cia = :CIA'
      'order by linea')
    Left = 417
    Top = 109
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_grupos: TDataSource
    AutoEdit = False
    DataSet = qry_grupos
    Left = 449
    Top = 41
  end
  object qry_grupos: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idgrupo, codigo, descri '
      'from inv_grupos  where cia = :CIA'
      'order by codigo')
    Left = 449
    Top = 109
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_buscod: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.idart, b.codigo, b.descri, b.tipo, b.costos, b.coston, ' +
        'b.piva'
      
        'from inv_invhist a join inven b on a.codigo = b.codigo and a.cia' +
        ' = b.cia'
      'where a.codigo like :CODIGO and a.cia = :CIA '
      'order by codigo')
    Left = 387
    Top = 40
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
  object dts_buscod: TDataSource
    DataSet = qry_buscod
    Left = 387
    Top = 109
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.idart, a.codigo, b.descri, b.linea'
      'from '
      
        'inv_invhist a join inven b on a.codigo = b.codigo and a.cia = b.' +
        'cia'
      'where a.codigo  = :CODIGO  and a.cia = :CIA')
    Left = 481
    Top = 79
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    AutoEdit = False
    DataSet = qry_inven
    Left = 481
    Top = 111
  end
  object qry_tipoplazo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_plazoslispre'
      'where tipolista = :TIPOLISTA and cia = :CIA'
      'order by cvepzo'
      '')
    Left = 353
    Top = 39
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOLISTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_tipoplazo: TDataSource
    AutoEdit = False
    DataSet = qry_tipoplazo
    Left = 353
    Top = 71
  end
end
