object Frame_datoscapentpro: TFrame_datoscapentpro
  Left = 0
  Top = 0
  Width = 587
  Height = 158
  TabOrder = 0
  object Label3: TLabel
    Left = 3
    Top = 14
    Width = 41
    Height = 13
    Caption = '&Almac�n'
    FocusControl = lkcmb_almacen
  end
  object Label1: TLabel
    Left = 323
    Top = 14
    Width = 37
    Height = 13
    Caption = 'N�mero'
    FocusControl = edt_nument
  end
  object Label4: TLabel
    Left = 443
    Top = 14
    Width = 30
    Height = 13
    Caption = 'Fecha'
    FocusControl = edt_nument
  end
  object Label14: TLabel
    Left = 16
    Top = 38
    Width = 28
    Height = 13
    Caption = 'Prove'
  end
  object Label17: TLabel
    Left = 441
    Top = 39
    Width = 35
    Height = 13
    Caption = 'Importe'
  end
  object Label18: TLabel
    Left = 461
    Top = 63
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object Label16: TLabel
    Left = 8
    Top = 133
    Width = 36
    Height = 13
    Caption = 'Factura'
    FocusControl = edt_facpro
  end
  object Label20: TLabel
    Left = 13
    Top = 62
    Width = 31
    Height = 13
    Caption = 'Plan P'
  end
  object Label21: TLabel
    Left = 289
    Top = 62
    Width = 29
    Height = 13
    Caption = 'Letras'
    FocusControl = edt_nulets
  end
  object Label31: TLabel
    Left = 353
    Top = 61
    Width = 26
    Height = 13
    Caption = 'Plazo'
    FocusControl = edt_plazo
  end
  object Label29: TLabel
    Left = 1
    Top = 86
    Width = 43
    Height = 13
    Caption = '1er Pago'
    FocusControl = edt_nument
  end
  object Label19: TLabel
    Left = 449
    Top = 86
    Width = 24
    Height = 13
    Caption = 'Total'
  end
  object Label26: TLabel
    Left = 146
    Top = 132
    Width = 23
    Height = 13
    Caption = 'Flete'
  end
  object Label30: TLabel
    Left = 3
    Top = 110
    Width = 41
    Height = 13
    Caption = 'Ult.Pago'
    FocusControl = edt_nument
  end
  object Label23: TLabel
    Left = 289
    Top = 87
    Width = 29
    Height = 13
    Caption = 'C.F.C.'
  end
  object Label22: TLabel
    Left = 166
    Top = 87
    Width = 37
    Height = 13
    Caption = 'Tasa E.'
  end
  object Label24: TLabel
    Left = 165
    Top = 110
    Width = 37
    Height = 13
    Caption = 'Tasa P.'
  end
  object Label25: TLabel
    Left = 289
    Top = 110
    Width = 29
    Height = 13
    Caption = 'C.F.P.'
  end
  object Label27: TLabel
    Left = 273
    Top = 132
    Width = 41
    Height = 13
    Caption = 'DesxApli'
  end
  object Label28: TLabel
    Left = 424
    Top = 107
    Width = 50
    Height = 13
    Caption = 'Gran Total'
  end
  object lkcmb_almacen: TDBLookupComboBox
    Left = 45
    Top = 10
    Width = 65
    Height = 21
    KeyField = 'CLAVE'
    ListField = 'CLAVE'
    ListSource = dts_almacen
    TabOrder = 0
    OnExit = lkcmb_almacenExit
  end
  object DBEdit1: TDBEdit
    Left = 114
    Top = 10
    Width = 199
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_almacen
    TabOrder = 1
  end
  object edt_nument: TdxCurrencyEdit
    Left = 368
    Top = 10
    Width = 43
    TabOrder = 2
    OnExit = edt_numentExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object date_fecha: TDateTimePicker
    Left = 480
    Top = 10
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 3
    OnExit = edt_plazoExit
  end
  object lkcmb_prove: TDBLookupComboBox
    Left = 45
    Top = 34
    Width = 65
    Height = 21
    DropDownWidth = 300
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_prove
    TabOrder = 4
  end
  object DBEdit3: TDBEdit
    Left = 114
    Top = 34
    Width = 297
    Height = 21
    TabStop = False
    DataField = 'NOMBRE'
    DataSource = dts_prove
    TabOrder = 5
  end
  object dxDBCurrencyEdit1: TdxDBCurrencyEdit
    Left = 480
    Top = 34
    Width = 90
    TabOrder = 6
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IMPORTE'
    StoredValues = 1
  end
  object dxDBCurrencyEdit2: TdxDBCurrencyEdit
    Left = 480
    Top = 58
    Width = 90
    TabOrder = 7
    TabStop = False
    Alignment = taRightJustify
    DataField = 'IVA'
    StoredValues = 1
  end
  object edt_facpro: TdxEdit
    Left = 45
    Top = 129
    Width = 90
    TabOrder = 19
    CharCase = ecUpperCase
    MaxLength = 10
    StoredValues = 2
  end
  object DBEdit2: TDBEdit
    Left = 114
    Top = 58
    Width = 170
    Height = 21
    TabStop = False
    DataField = 'DESCRI'
    DataSource = dts_planesp
    TabOrder = 8
  end
  object lkcmb_planp: TDBLookupComboBox
    Left = 45
    Top = 58
    Width = 66
    Height = 21
    DropDownWidth = 300
    KeyField = 'CLAVE'
    ListField = 'STRCLAVE'
    ListSource = dts_planesp
    TabOrder = 9
  end
  object edt_nulets: TdxCurrencyEdit
    Left = 321
    Top = 58
    Width = 28
    TabOrder = 10
    OnExit = edt_plazoExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object edt_plazo: TdxCurrencyEdit
    Left = 385
    Top = 58
    Width = 26
    TabOrder = 11
    OnExit = edt_plazoExit
    Alignment = taRightJustify
    DecimalPlaces = 0
    DisplayFormat = '0'
    Value = 1
    StoredValues = 1
  end
  object date_prpago: TDateTimePicker
    Left = 45
    Top = 82
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 12
    OnExit = date_prpagoExit
  end
  object dxDBCurrencyEdit3: TdxDBCurrencyEdit
    Left = 480
    Top = 81
    Width = 90
    TabOrder = 18
    TabStop = False
    Alignment = taRightJustify
    DataField = 'TOTAL'
    StoredValues = 1
  end
  object edt_flete: TdxCurrencyEdit
    Left = 178
    Top = 129
    Width = 90
    TabOrder = 20
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object date_ulpago: TDateTimePicker
    Left = 45
    Top = 106
    Width = 90
    Height = 21
    CalAlignment = dtaLeft
    Date = 37548.4553024306
    Time = 37548.4553024306
    DateFormat = dfShort
    DateMode = dmComboBox
    Kind = dtkDate
    ParseInput = False
    TabOrder = 13
  end
  object edt_cfc: TdxCurrencyEdit
    Left = 321
    Top = 82
    Width = 90
    TabOrder = 15
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_tasaent: TdxCurrencyEdit
    Left = 206
    Top = 82
    Width = 62
    TabOrder = 14
    DecimalPlaces = 4
    DisplayFormat = '0.00000;-0.00000'
    StoredValues = 0
  end
  object edt_tasapro: TdxCurrencyEdit
    Left = 206
    Top = 106
    Width = 62
    TabOrder = 16
    DecimalPlaces = 4
    DisplayFormat = '0.00000;-0.00000'
    StoredValues = 0
  end
  object edt_cfp: TdxCurrencyEdit
    Left = 321
    Top = 106
    Width = 90
    TabOrder = 17
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_desxapli: TdxCurrencyEdit
    Left = 321
    Top = 129
    Width = 90
    TabOrder = 21
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object edt_grtotal: TdxCurrencyEdit
    Left = 480
    Top = 105
    Width = 90
    TabOrder = 22
    Alignment = taRightJustify
    DisplayFormat = '$,0.00;-$,0.00'
    StoredValues = 1
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, nombre from Almacen where exib = '#39'A'#39' and Cia = :Ci' +
        'a'
      'order by clave'
      '')
    Left = 218
    Top = 8
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object dts_almacen: TDataSource
    AutoEdit = False
    DataSet = qry_almacen
    Left = 218
    Top = 40
  end
  object qry_prove: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, nombre'
      'from proveedor'
      'where cia = :CIA order by codigo')
    Left = 253
    Top = 8
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_prove: TDataSource
    DataSet = qry_prove
    Left = 252
    Top = 39
  end
  object qry_planesp: TQuery
    AfterScroll = qry_planespAfterScroll
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave, descri, numlet, ivadis, nletiva, feciva, plazo, ta' +
        'sa, fletedis, letivaemp, letivasol, intssal,'
      'dscxapdis, cia, cast(clave as varchar(3)) as strclave'
      'from planesp where cia = :CIA'
      'order by clave'
      ''
      ' ')
    Left = 216
    Top = 72
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_planesp: TDataSource
    DataSet = qry_planesp
    Left = 216
    Top = 104
  end
  object qry_entradas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select TIPO, ALM, RECEMI, NUMERO, FACPRO, PROVE, PERENVREC, STAT' +
        'US,'
      'CONIVA, FECHA, IMPORTE, IVA, TOTAL, vence,'
      'ctofin,tascomp, taspro, fechafac,'
      
        'LETRAS, PLAZOCFP, PLANP, FLETES, DESXAP, FECHAPRP, CTOFINCOMP, U' +
        'SUARIO, CIA'
      
        'from Entradas where tipo= :Tipo and alm=:Alm and numero= :Numero' +
        ' and cia=:Cia')
    Left = 186
    Top = 8
    ParamData = <
      item
        DataType = ftString
        Name = 'tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Alm'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Numero'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object uqry_entradas: TUpdateSQL
    ModifySQL.Strings = (
      'update Entradas'
      'set'
      '  RECEMI = :RECEMI,'
      '  FACPRO = :FACPRO,'
      '  PROVE = :PROVE,'
      '  PERENVREC = :PERENVREC,'
      '  STATUS = :STATUS,'
      '  CONIVA = :CONIVA,'
      '  FECHA = :FECHA,'
      '  IMPORTE = :IMPORTE,'
      '  IVA = :IVA,'
      '  TOTAL = :TOTAL,'
      '  VENCE = :VENCE,'
      '  CTOFIN = :CTOFIN,'
      '  TASCOMP = :TASCOMP,'
      '  TASPRO = :TASPRO,'
      '  FECHAFAC = :FECHAFAC,'
      '  LETRAS = :LETRAS,'
      '  PLAZOCFP = :PLAZOCFP,'
      '  PLANP = :PLANP,'
      '  FLETES = :FLETES,'
      '  DESXAP = :DESXAP,'
      '  FECHAPRP = :FECHAPRP,'
      '  CTOFINCOMP = :CTOFINCOMP,'
      '  USUARIO = :USUARIO'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into Entradas'
      '  (TIPO, ALM, RECEMI, NUMERO, FACPRO, PROVE, PERENVREC, STATUS, '
      'CONIVA, '
      '   FECHA, IMPORTE, IVA, TOTAL, VENCE, CTOFIN, TASCOMP, TASPRO, '
      'FECHAFAC, '
      
        '   LETRAS, PLAZOCFP, PLANP, FLETES, DESXAP, FECHAPRP, CTOFINCOMP' +
        ', '
      'USUARIO, '
      '   CIA)'
      'values'
      
        '  (:TIPO, :ALM, :RECEMI, :NUMERO, :FACPRO, :PROVE, :PERENVREC, :' +
        'STATUS, '
      
        '   :CONIVA, :FECHA, :IMPORTE, :IVA, :TOTAL, :VENCE, :CTOFIN, :TA' +
        'SCOMP, '
      
        '   :TASPRO, :FECHAFAC, :LETRAS, :PLAZOCFP, :PLANP, :FLETES, :DES' +
        'XAP, '
      ':FECHAPRP, '
      '   :CTOFINCOMP, :USUARIO, :CIA)')
    DeleteSQL.Strings = (
      'delete from Entradas'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CIA = :OLD_CIA')
    Left = 325
    Top = 32
  end
  object dts_entradas: TDataSource
    AutoEdit = False
    DataSet = qry_entradas
    Left = 183
    Top = 40
  end
  object qry_renentra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.*, b.descri, b.precio, (a.costou * (a.piva / 100 + 1) )' +
        ' as costoneto'
      'from renentra a'
      'join inven b on b.codigo = a.codinv and b.cia = a.Cia'
      'where  a.tipo=:Tipo and a.alm=:Alm and a.numero=:Numero '
      'and a.cia=:cia order by a.conse')
    Left = 338
    Top = 83
    ParamData = <
      item
        DataType = ftInteger
        Name = 'Tipo'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Alm'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Numero'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'cia'
        ParamType = ptUnknown
      end>
  end
  object dtsRenEntra: TDataSource
    DataSet = qry_renentra
    Left = 369
    Top = 115
  end
  object uqry_renentra: TUpdateSQL
    ModifySQL.Strings = (
      'update RenEntra'
      'set'
      '  TIPO = :TIPO,'
      '  ALM = :ALM,'
      '  RECEMI = :RECEMI,'
      '  NUMERO = :NUMERO,'
      '  CONSE = :CONSE,'
      '  CODINV = :CODINV,'
      '  SERIE = :SERIE,'
      '  SIONO = :SIONO,'
      '  FOLSAL = :FOLSAL,'
      '  FOLENT = :FOLENT,'
      '  UNIDS = :UNIDS,'
      '  COSTOU = :COSTOU,'
      '  PIVA = :PIVA,'
      '  IMPORTE = :IMPORTE,'
      '  CANTMUEVE = :CANTMUEVE,'
      '  STATUS = :STATUS,'
      '  PERSENVREC = :PERSENVREC,'
      '  CIA = :CIA,'
      '  VEND = :VEND,'
      '  POBLAC = :POBLAC,'
      '  TIPAGO = :TIPAGO,'
      '  PRVTA = :PRVTA,'
      '  ENTOSAL = :ENTOSAL,'
      '  ENTCAN = :ENTCAN'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into RenEntra'
      
        '  (TIPO, ALM, RECEMI, NUMERO, CONSE, CODINV, SERIE, SIONO, FOLSA' +
        'L, '
      'FOLENT, '
      
        '   UNIDS, COSTOU, PIVA, IMPORTE, CANTMUEVE, STATUS, PERSENVREC, ' +
        'CIA, '
      'VEND, '
      '   POBLAC, TIPAGO, PRVTA, ENTOSAL, ENTCAN)'
      'values'
      
        '  (:TIPO, :ALM, :RECEMI, :NUMERO, :CONSE, :CODINV, :SERIE, :SION' +
        'O, :FOLSAL, '
      
        '   :FOLENT, :UNIDS, :COSTOU, :PIVA, :IMPORTE, :CANTMUEVE, :STATU' +
        'S, '
      ':PERSENVREC, '
      '   :CIA, :VEND, :POBLAC, :TIPAGO, :PRVTA, :ENTOSAL, :ENTCAN)')
    DeleteSQL.Strings = (
      'delete from RenEntra'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA')
    Left = 336
    Top = 114
  end
end
