object Frame_datosrenpolcampre: TFrame_datosrenpolcampre
  Left = 0
  Top = 0
  Width = 477
  Height = 269
  TabOrder = 0
  object lbl_numero: TLabel
    Left = 69
    Top = 11
    Width = 33
    Height = 13
    Caption = 'Código'
  end
  object lbl_precioant: TLabel
    Left = 264
    Top = 61
    Width = 69
    Height = 13
    Caption = 'Precio Anterior'
  end
  object lbl_precionvo: TLabel
    Left = 37
    Top = 61
    Width = 65
    Height = 13
    Caption = 'Precio Nuevo'
  end
  object lbl_subsidioant: TLabel
    Left = 232
    Top = 85
    Width = 101
    Height = 13
    Caption = 'Precio Anter Subsidio'
  end
  object lbl_subsidionvo: TLabel
    Left = 6
    Top = 85
    Width = 96
    Height = 13
    Caption = 'Precio Nvo Subsidio'
  end
  object lbl_costorepo: TLabel
    Left = 30
    Top = 179
    Width = 72
    Height = 13
    Caption = 'Cto Reposicion'
    Visible = False
  end
  object lbl_precioxtensa: TLabel
    Left = 267
    Top = 179
    Width = 66
    Height = 13
    Caption = 'Precio Xtensa'
    Visible = False
  end
  object lbl_garantia: TLabel
    Left = 60
    Top = 133
    Width = 42
    Height = 13
    Caption = 'Garantía'
  end
  object lbl_descri: TLabel
    Left = 46
    Top = 35
    Width = 56
    Height = 13
    Caption = 'Descripción'
  end
  object lbl_observs: TLabel
    Left = 31
    Top = 155
    Width = 71
    Height = 13
    Caption = 'Observaciones'
  end
  object lbl_situanvo: TLabel
    Left = 23
    Top = 109
    Width = 79
    Height = 13
    Caption = 'Nueva Situación'
  end
  object lbl_situaant: TLabel
    Left = 250
    Top = 107
    Width = 83
    Height = 13
    Caption = 'Situación Anterior'
  end
  object edt_codigo: TEdit
    Left = 105
    Top = 7
    Width = 120
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 0
    OnExit = edt_codigoExit
    OnKeyDown = edt_codigoKeyDown
  end
  object edt_descri: TEdit
    Left = 105
    Top = 31
    Width = 357
    Height = 21
    TabStop = False
    CharCase = ecUpperCase
    ReadOnly = True
    TabOrder = 8
  end
  object edt_precioant: TdxCurrencyEdit
    Left = 342
    Top = 55
    Width = 120
    TabOrder = 9
    TabStop = False
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_precionvo: TdxCurrencyEdit
    Left = 105
    Top = 55
    Width = 120
    TabOrder = 1
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_fideant: TdxCurrencyEdit
    Left = 342
    Top = 79
    Width = 120
    TabOrder = 10
    TabStop = False
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_fidenvo: TdxCurrencyEdit
    Left = 105
    Top = 79
    Width = 120
    TabOrder = 2
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_costoxten: TdxCurrencyEdit
    Left = 105
    Top = 175
    Width = 120
    TabOrder = 3
    Visible = False
    OnExit = edt_costoxtenExit
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_precioxten: TdxCurrencyEdit
    Left = 342
    Top = 175
    Width = 120
    TabOrder = 4
    Visible = False
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object lkcmb_garantia: TDBLookupComboBox
    Left = 105
    Top = 127
    Width = 120
    Height = 21
    KeyField = 'IDGARANTIA'
    ListField = 'CLAVE'
    ListSource = dts_garantias
    TabOrder = 6
    OnExit = lkcmb_garantiaExit
  end
  object edt_observs: TEdit
    Left = 105
    Top = 151
    Width = 357
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 7
  end
  object dbedt_garantia: TDBEdit
    Left = 228
    Top = 127
    Width = 234
    Height = 21
    TabStop = False
    DataField = 'DESCRI'
    DataSource = dts_garantias
    TabOrder = 11
  end
  object lkcmb_situaciones: TDBLookupComboBox
    Left = 105
    Top = 103
    Width = 120
    Height = 21
    KeyField = 'IDSITUAC'
    ListField = 'SITUACION'
    ListSource = dts_situaciones
    TabOrder = 5
  end
  object edt_antsit: TEdit
    Left = 342
    Top = 103
    Width = 120
    Height = 21
    TabStop = False
    CharCase = ecUpperCase
    ReadOnly = True
    TabOrder = 12
  end
  object qry_inven: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, descri, tipo, costos, coston, piva, precio, linea' +
        ', empaqe, precelec'
      'from inven where codigo = :CODIGO and cia = :CIA order by codigo'
      ' '
      ' ')
    Left = 407
    Top = 205
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
    Left = 439
    Top = 205
  end
  object qry_garantias: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_garantias where cia = :CIA order by meses')
    Left = 407
    Top = 237
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_garantias: TDataSource
    DataSet = qry_garantias
    Left = 439
    Top = 237
  end
  object qry_situaciones: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_situaciones order by situacion')
    Left = 327
    Top = 237
  end
  object dts_situaciones: TDataSource
    DataSet = qry_situaciones
    Left = 359
    Top = 237
  end
  object qry_invxtensa: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select b.* from inv_invhist a join inv_extensa b on a.idart = b.' +
        'idart'
      'where a.codigo = :CODIGO and a.cia = :CIA ')
    UpdateObject = uqry_invxtensa
    Left = 327
    Top = 205
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
  object qry_invgarantia: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select b.* from inv_invhist a join inv_relinv c on a.idart = c.i' +
        'dart'
      'join inv_garantias b on c.iddato = b.idgarantia'
      'where a.codigo = :CODIGO and a.cia = :CIA and c.idrel = :IDREL'
      '')
    Left = 359
    Top = 205
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
      end
      item
        DataType = ftUnknown
        Name = 'IDREL'
        ParamType = ptUnknown
      end>
  end
  object uqry_invxtensa: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_extensa'
      'set'
      '  PRECIOEXT = :PRECIOEXT,'
      '  COSTOEXT = :COSTOEXT'
      'where'
      '  IDEXTENSA = :OLD_IDEXTENSA ')
    InsertSQL.Strings = (
      'insert into inv_extensa'
      '  (IDEXTENSA, IDART, PRECIOEXT, COSTOEXT, CIA)'
      'values'
      '  (:IDEXTENSA, :IDART, :PRECIOEXT, :COSTOEXT, :CIA)')
    DeleteSQL.Strings = (
      'delete from inv_extensa'
      'where'
      '  IDEXTENSA = :OLD_IDEXTENSA ')
    Left = 298
    Top = 202
  end
  object qry_invhist: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_invhist '
      'where codigo = :CODIGO and cia = :CIA'
      '')
    Left = 295
    Top = 237
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
end
