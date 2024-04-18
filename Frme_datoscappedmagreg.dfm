object Frame_datoscappedmagrega: TFrame_datoscappedmagrega
  Left = 0
  Top = 0
  Width = 696
  Height = 69
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
    Left = 540
    Top = 13
    Width = 103
    TabOrder = 3
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 0
  end
  object lkcmb_codigos: TDBLookupComboBox
    Left = 560
    Top = 37
    Width = 119
    Height = 21
    DropDownWidth = 300
    KeyField = 'CODIGO'
    ListField = 'CODIGO; descri'
    ListSource = dts_buscod
    TabOrder = 4
    Visible = False
    OnExit = lkcmb_codigosExit
    OnKeyDown = lkcmb_codigosKeyDown
  end
  object qry_buscod: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, descri, tipo, costos, coston, piva'
      'from inven where codigo like :CODIGO and cia = :CIA'
      'order by codigo'
      '')
    Left = 111
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
  object dts_buscod: TDataSource
    DataSet = qry_buscod
    Left = 142
    Top = 37
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, descri, tipo, costos, coston, piva, precio, empaq' +
        'e as situacion'
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
end
