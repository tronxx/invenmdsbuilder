object Form_analifon: TForm_analifon
  Left = 285
  Top = 174
  Width = 657
  Height = 454
  Caption = 'Analitico de Salidas FONACOT'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 649
    Height = 129
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object pnl_datos: TGroupBox
      Left = 8
      Top = 1
      Width = 193
      Height = 80
      Caption = 'Fecha:'
      TabOrder = 0
      object lbl_vigencia: TLabel
        Left = 6
        Top = 18
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
      end
      object lbl_corte: TLabel
        Left = 7
        Top = 46
        Width = 58
        Height = 13
        Caption = 'Fecha Final:'
      end
      object date_ini: TDateTimePicker
        Left = 69
        Top = 14
        Width = 90
        Height = 22
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
        OnExit = date_iniExit
      end
      object date_fin: TDateTimePicker
        Left = 69
        Top = 41
        Width = 92
        Height = 22
        CalAlignment = dtaLeft
        Date = 38982.3491966782
        Time = 38982.3491966782
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
    object GroupBox3: TGroupBox
      Left = 208
      Top = 1
      Width = 162
      Height = 80
      Caption = 'Almacenes:'
      TabOrder = 1
      object Label1: TLabel
        Left = 7
        Top = 20
        Width = 61
        Height = 13
        Caption = 'Del Amacen:'
      end
      object Label3: TLabel
        Left = 6
        Top = 42
        Width = 56
        Height = 13
        Caption = 'Al Almacen:'
      end
      object edt_almini: TEdit
        Left = 69
        Top = 15
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_almfin: TEdit
        Left = 70
        Top = 39
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
        Text = 'ZZ'
      end
    end
    object GroupBox5: TGroupBox
      Left = 9
      Top = 81
      Width = 528
      Height = 40
      Caption = 'Reporte De:'
      TabOrder = 3
      object rbtn_fona: TRadioButton
        Left = 8
        Top = 18
        Width = 113
        Height = 17
        Caption = 'Fonacot'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_imevi: TRadioButton
        Left = 111
        Top = 18
        Width = 88
        Height = 17
        Caption = 'Imevi'
        TabOrder = 1
      end
      object rbtn_fide: TRadioButton
        Left = 216
        Top = 18
        Width = 77
        Height = 17
        Caption = 'FIDE'
        TabOrder = 2
      end
      object rbtn_cel: TRadioButton
        Left = 303
        Top = 18
        Width = 77
        Height = 17
        Caption = 'Celular'
        Enabled = False
        TabOrder = 3
        Visible = False
      end
    end
    object GroupBox6: TGroupBox
      Left = 375
      Top = 1
      Width = 162
      Height = 80
      Caption = 'Situaciones:'
      TabOrder = 2
      object Label2: TLabel
        Left = 7
        Top = 17
        Width = 75
        Height = 13
        Caption = 'De la Situacion:'
      end
      object Label4: TLabel
        Left = 8
        Top = 39
        Width = 68
        Height = 13
        Caption = 'A la Situacion:'
      end
      object edt_situini: TEdit
        Left = 83
        Top = 13
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_situfin: TEdit
        Left = 83
        Top = 36
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
        Text = 'ZZ'
      end
    end
    object BitBtn1: TBitBtn
      Left = 549
      Top = 38
      Width = 76
      Height = 26
      Action = imprimir_reporte
      Caption = 'Reporte'
      TabOrder = 4
      Kind = bkOK
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 129
    Width = 649
    Height = 291
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'RECEMI'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    TabOrder = 1
    DataSource = dts_llena
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_renglonesRECEMI: TdxDBGridMaskColumn
      Caption = 'Punto de Venta'
      Sorted = csUp
      Visible = False
      Width = 157
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RECEMI'
      GroupIndex = 0
    end
    object dbgrd_renglonesCODINV: TdxDBGridMaskColumn
      Caption = 'Codigo'
      Width = 85
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODINV'
    end
    object dbgrd_renglonesDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripcion'
      Width = 152
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_renglonesCONCEPTO: TdxDBGridMaskColumn
      Caption = 'Nombre del Cliente'
      Width = 180
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CONCEPTO'
    end
    object dbgrd_renglonesUNIDS: TdxDBGridMaskColumn
      Caption = 'Cantidad'
      Width = 60
      BandIndex = 0
      RowIndex = 0
      FieldName = 'UNIDS'
    end
    object dbgrd_renglonesTOTAL: TdxDBGridCurrencyColumn
      Caption = 'Total'
      Width = 98
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TOTAL'
      SummaryFooterType = cstSum
      SummaryFooterField = 'TOTAL'
      SummaryFooterFormat = '$,0.00;-$,0.00'
    end
    object dbgrd_renglonesTIPO: TdxDBGridMaskColumn
      Caption = 'Tipo'
      Width = 54
      BandIndex = 0
      RowIndex = 0
      FieldName = 'TIPO'
    end
  end
  object qry_punto: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select unique a.recemi,d.nombre from entradas b join renentra a'
      'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      'b.cia=a.cia'
      'join inven c on a.codinv = c.codigo and a.cia = c.cia'
      'join ptovta d on d.clave =  a.recemi'
      
        'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FEC' +
        'INI and :FECFIN'
      
        'and (b.tipo= :PVTA or b.tipo= :PCAN) and b.cia= :CIA and c.empaq' +
        'e between :EMPINI and :EMPFIN')
    Left = 64
    Top = 190
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_analitico: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.codinv,d.descri,c.concepto,a.unids,'
      #9'a.importe*((a.piva/100)+1) as total, b.tipo'
      '        from entradas b join  renentra a'
      #9'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      
        '        b.cia=a.cia join inven d on a.codinv=d.codigo and a.cia ' +
        '= d.cia'
      '        join conceps c on a.persenvrec=c.ncon'
      
        #9'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FE' +
        'CINI and :FECFIN'
      
        '        and (b.tipo= :PVTA or b.tipo= :PCAN)  and a.recemi = :RE' +
        'CEMI and b.cia= :CIA'
      '        and d.empaqe between :EMPINI and :EMPFIN')
    Left = 64
    Top = 259
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_totline: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as total'
      #9'from entradas b join renentra a'
      #9'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      
        '        b.cia=a.cia join inven c on a.codinv=c.codigo and b.cia=' +
        'c.cia'
      
        #9'where b.alm between  :ALMINI and :ALMFIN and b.fecha between  :' +
        'FECINI and :FECFIN and b.tipo= :PVTA'
      
        '        and a.recemi= :RECEMI and c.linea= :LINEA and b.cia= :CI' +
        'A and c.empaqe between :EMPINI and :EMPFIN')
    Left = 64
    Top = 223
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_lineas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select unique c.numero, c.orden, c.descri from entradas b join  ' +
        'renentra a'
      'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      'b.cia=a.cia join inven d on a.codinv=d.codigo and a.cia = d.cia'
      'join lineas c on d.linea = c.numero and b.cia=c.cia'
      
        'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FEC' +
        'INI and :FECFIN'
      'and (b.tipo= :PVTA or b.tipo= :PCAN) and b.cia= :CIA'
      'and d.empaqe between :EMPINI and :EMPFIN')
    Left = 102
    Top = 190
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object dts_llena: TDataSource
    DataSet = qry_llena
    Left = 96
    Top = 363
  end
  object qry_totsuc: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as totsuc'
      #9'from entradas b join renentra a'
      #9'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      '        b.cia=a.cia'
      '        join inven c on a.codinv = c.codigo and a.cia = c.cia'
      
        #9'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FE' +
        'CINI and :FECFIN and b.tipo= :PVTA'
      
        '        and a.recemi= :RECEMI and b.cia= :CIA and c.empaqe betwe' +
        'en :EMPINI and :EMPFIN')
    Left = 64
    Top = 294
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_gtotal: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe*((a.piva/100)+1)) as totsuc'
      #9'from entradas b join renentra a'
      #9'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      '        b.cia=a.cia'
      '        join inven c on a.codinv = c.codigo and a.cia = c.cia'
      
        #9'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FE' +
        'CINI and :FECFIN and b.tipo= :PVTA'
      '        and b.cia= :CIA and c.empaqe between :EMPINI and :EMPFIN')
    Left = 64
    Top = 328
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_llena: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      ''
      'select a.recemi ,a.codinv,d.descri,c.concepto,a.unids,'
      #9'a.importe*((a.piva/100)+1) as total, b.tipo'
      '        from entradas b join  renentra a'
      #9'on b.alm=a.alm and b.numero=a.numero and b.tipo=a.tipo and'
      
        '        b.cia=a.cia join inven d on a.codinv=d.codigo and a.cia ' +
        '= d.cia'
      '        join conceps c on a.persenvrec=c.ncon'
      
        #9'where b.alm between :ALMINI and :ALMFIN and b.fecha between :FE' +
        'CINI and :FECFIN'
      '        and (b.tipo= :PVTA or b.tipo= :PCAN)    and b.cia= :CIA '
      
        '        and d.empaqe between :EMPINI and :EMPFIN order by a.rece' +
        'mi ')
    Left = 64
    Top = 361
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'EMPFIN'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 344
    Top = 264
    object imprimir_reporte: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = imprimir_reporteExecute
    end
  end
end
