object Frame_datosrenfacma: TFrame_datosrenfacma
  Left = 0
  Top = 0
  Width = 659
  Height = 68
  TabOrder = 0
  object Label8: TLabel
    Left = 5
    Top = 16
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object Label12: TLabel
    Left = 468
    Top = 16
    Width = 42
    Height = 13
    Caption = 'Cantidad'
    FocusControl = edt_canti
  end
  object Label10: TLabel
    Left = 5
    Top = 37
    Width = 41
    Height = 13
    Caption = 'Precio U'
  end
  object Label19: TLabel
    Left = 181
    Top = 37
    Width = 36
    Height = 13
    Caption = '%Dscto'
  end
  object lbl_series: TLabel
    Left = 296
    Top = 38
    Width = 35
    Height = 13
    Caption = 'Serie(s)'
  end
  object lbl_piva: TLabel
    Left = 580
    Top = 16
    Width = 23
    Height = 13
    Caption = '%Iva'
    Visible = False
  end
  object edt_codigo: TEdit
    Left = 48
    Top = 12
    Width = 121
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 15
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object edt_descri: TEdit
    Left = 172
    Top = 12
    Width = 285
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 30
    ReadOnly = True
    TabOrder = 1
  end
  object edt_canti: TdxCurrencyEdit
    Left = 513
    Top = 12
    Width = 52
    TabOrder = 2
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object edt_preciou: TdxCurrencyEdit
    Left = 48
    Top = 34
    Width = 121
    TabOrder = 3
    Alignment = taRightJustify
    StoredValues = 1
  end
  object edt_pdsc: TdxCurrencyEdit
    Left = 224
    Top = 34
    Width = 58
    TabOrder = 4
    Alignment = taRightJustify
    DisplayFormat = '0.00;-0.00'
    StoredValues = 1
  end
  object lst_series: TComboBox
    Left = 337
    Top = 35
    Width = 121
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 5
  end
  object btn_series: TButton
    Left = 460
    Top = 35
    Width = 75
    Height = 21
    Action = selecciona_series
    TabOrder = 6
  end
  object edt_piva: TdxCurrencyEdit
    Left = 608
    Top = 12
    Width = 40
    TabOrder = 7
    Visible = False
    Alignment = taRightJustify
    DisplayFormat = '0.00;-0.00'
    Value = 16
    StoredValues = 1
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select 0 as idart, codigo, descri, tipo, costos, coston, piva, p' +
        'recio,empaqe as  situacion'
      'from inven'
      'where (codigo like :CODIGO and cia = :CIA ) or cia = :IDART'
      'order by codigo')
    Left = 463
    Top = 5
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
      end
      item
        DataType = ftInteger
        Name = 'IDART'
        ParamType = ptUnknown
      end>
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 455
    Top = 42
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 352
    object selecciona_series: TAction
      Caption = 'Series'
      ImageIndex = 27
      OnExecute = selecciona_seriesExecute
    end
  end
  object qry_extensa: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idextensa, a.idart, precioext, costoext'
      'from inv_invhist a join inv_extensa b on a.idart = b.idart'
      'where a.codigo = :CODIGO and a.cia = :CIA'
      ''
      '')
    Left = 503
    Top = 5
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
end
