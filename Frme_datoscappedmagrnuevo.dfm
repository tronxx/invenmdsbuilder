object Frame_datoscappedmagrnuevo: TFrame_datoscappedmagrnuevo
  Left = 0
  Top = 0
  Width = 661
  Height = 71
  TabOrder = 0
  object Label8: TLabel
    Left = 12
    Top = 17
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label12: TLabel
    Left = 407
    Top = 17
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object lbl_costo: TLabel
    Left = 507
    Top = 17
    Width = 30
    Height = 13
    Caption = 'Precio'
    FocusControl = edt_canti
  end
  object edt_codigo: TEdit
    Left = 48
    Top = 13
    Width = 113
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object edt_descri: TEdit
    Left = 162
    Top = 13
    Width = 239
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 1
  end
  object edt_canti: TdxCurrencyEdit
    Left = 453
    Top = 13
    Width = 26
    TabOrder = 2
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object edt_costou: TdxCurrencyEdit
    Left = 544
    Top = 13
    Width = 105
    TabOrder = 3
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, descri, tipo, costos, coston, piva, precio, empaq' +
        'e as situacion,'
      'prove'
      'from inven where codigo =  :CODIGO and cia = :CIA')
    Left = 177
    Top = 37
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
    Left = 209
    Top = 37
  end
  object qry_preciomaypro: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select idplazocrd, a.linea as prove, a.idlinea, plistamax as fac' +
        'torprecio, a.tipo, a.cia'
      'from plazoscrd a'
      'where a.linea = :PROVE and a.cia = :CIA and  a.tipo = :TIPO'
      '')
    Left = 280
    Top = 37
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO'
        ParamType = ptUnknown
      end>
  end
end
