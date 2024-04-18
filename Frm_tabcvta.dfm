object Form_tabcvta: TForm_tabcvta
  Left = 258
  Top = 157
  Width = 696
  Height = 480
  Caption = 'Costo de Ventas x Ubicacion'
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
    Width = 688
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 180
      Height = 137
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      object Label1: TLabel
        Left = 5
        Top = 16
        Width = 60
        Height = 13
        Caption = 'Fecha Inicial'
      end
      object Label2: TLabel
        Left = 5
        Top = 40
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object date_fecini: TDateTimePicker
        Left = 77
        Top = 13
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
        OnExit = date_feciniExit
      end
      object date_fecfin: TDateTimePicker
        Left = 77
        Top = 37
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
        OnExit = date_feciniExit
      end
      object chk_reacumular: TCheckBox
        Left = 8
        Top = 64
        Width = 153
        Height = 17
        Alignment = taLeftJustify
        Caption = 'Acumular Datos'
        TabOrder = 2
      end
    end
    object BitBtn1: TBitBtn
      Left = 11
      Top = 88
      Width = 75
      Height = 25
      TabOrder = 1
      OnClick = BitBtn1Click
      Kind = bkOK
    end
    object grp_tiporep: TRadioGroup
      Left = 180
      Top = 0
      Width = 100
      Height = 137
      Align = alLeft
      Caption = 'Reporte de'
      ItemIndex = 0
      Items.Strings = (
        'Total'
        'Menudeo'
        'Fonacot'
        'Fide'
        'Imevi')
      TabOrder = 2
    end
    object GroupBox1: TGroupBox
      Left = 465
      Top = 0
      Width = 185
      Height = 137
      Align = alLeft
      Caption = 'Año Anterior'
      TabOrder = 3
      object Label3: TLabel
        Left = 5
        Top = 16
        Width = 60
        Height = 13
        Caption = 'Fecha Inicial'
      end
      object Label4: TLabel
        Left = 5
        Top = 40
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object date_anuantini: TDateTimePicker
        Left = 77
        Top = 13
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_anuantfin: TDateTimePicker
        Left = 77
        Top = 37
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
    object GroupBox2: TGroupBox
      Left = 280
      Top = 0
      Width = 185
      Height = 137
      Align = alLeft
      Caption = 'Mes Anterior'
      TabOrder = 4
      object Label5: TLabel
        Left = 5
        Top = 16
        Width = 60
        Height = 13
        Caption = 'Fecha Inicial'
      end
      object Label6: TLabel
        Left = 5
        Top = 40
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object date_mesantini: TDateTimePicker
        Left = 77
        Top = 13
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_mesantfin: TDateTimePicker
        Left = 77
        Top = 37
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 137
    Width = 688
    Height = 309
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_analisma
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_renglonesLINEA: TdxDBGridMaskColumn
      Caption = 'Linea'
      Sorted = csUp
      Visible = False
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LINEA'
      GroupIndex = 0
    end
    object dbgrd_renglonesCODIGO: TdxDBGridMaskColumn
      Caption = 'Codigo'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_renglonesDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_renglonesEMPAQE: TdxDBGridMaskColumn
      Caption = 'Empaque'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'EMPAQE'
    end
    object dbgrd_renglonesUNIDS: TdxDBGridMaskColumn
      Caption = 'Unidades'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'UNIDS'
      SummaryFooterType = cstSum
      SummaryFooterField = 'UNIDS'
      SummaryFooterFormat = '0'
    end
    object dbgrd_renglonesCOSTOTOT: TdxDBGridCurrencyColumn
      Caption = 'Total'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOTOT'
      SummaryFooterType = cstSum
      SummaryFooterField = 'COSTOTOT'
      SummaryFooterFormat = '$,0.00;-$,0.00'
    end
  end
  object qry_analisma: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select d.orden, c.linea, c.codigo, c.descri, c.empaqe,'
      #9'sum(b.unids * f.factor) as unids,'
      '        sum(b.costou * (b.piva/100+1) * f.factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo and f.idtipovta = 1'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      '        and a.tipo = b.tipo'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join lineas d on c.linea=d.numero'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        group by d.orden,linea,codigo,c.descri,c.empaqe'
      ' '
      ' '
      ' ')
    Left = 312
    Top = 200
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_gpodiary: TUpdateSQL
    ModifySQL.Strings = (
      'update gpodiary'
      'set'
      '  DESCRI = :DESCRI,'
      '  IMPRIME = :IMPRIME'
      'where'
      '  IDGPODIARY = :OLD_IDGPODIARY')
    InsertSQL.Strings = (
      'insert into gpodiary'
      '  (IDGPODIARY, GRUPO, DESCRI, IMPRIME, CIA)'
      'values'
      '  (:IDGPODIARY, :GRUPO, :DESCRI, :IMPRIME, :CIA)')
    DeleteSQL.Strings = (
      'delete from gpodiary'
      'where'
      '  IDGPODIARY = :OLD_IDGPODIARY')
    Left = 342
    Top = 200
  end
  object dts_analisma: TDataSource
    AutoEdit = False
    DataSet = qry_analisma
    Left = 372
    Top = 200
  end
  object PopupMenu1: TPopupMenu
    Left = 256
    Top = 248
    object Exportara1: TMenuItem
      Action = exporta_dbgrd
    end
    object Imprimir1: TMenuItem
      Action = imprimir_reporte
    end
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 552
    Top = 280
    object exporta_dbgrd: TAction
      Caption = 'Exportar a...'
      OnExecute = exporta_dbgrdExecute
    end
    object imprimir_reporte: TAction
      Caption = 'Reporte'
      OnExecute = imprimir_reporteExecute
    end
  end
  object qry_analixalm: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.recemi,'
      #9'sum(b.unids * f.factor) as unids,'
      '        sum(b.costou * (b.piva/100+1) * f.factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo and f.idtipovta = 1'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      '        and a.tipo = b.tipo'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join lineas d on c.linea=d.numero'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        and c.linea = :LINEA'
      '        group by b.recemi'
      ''
      ' '
      ' '
      ' ')
    Left = 312
    Top = 232
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end>
  end
  object qry_analixart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.recemi, b.codinv,'
      #9'sum(b.unids * f.factor) as unids,'
      '        sum(b.costou * (b.piva/100+1) * f.factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo and f.idtipovta = 1'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      '        and a.tipo = b.tipo'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join lineas d on c.linea=d.numero'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        and b.codinv = :CODIGO'
      '        group by b.recemi, b.codinv'
      ' '
      ' '
      ' ')
    UpdateObject = uqry_gpodiary
    Left = 344
    Top = 232
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end>
  end
  object qry_lineas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select numero as linea, descri from lineas where cia = :CIA orde' +
        'r by orden, numero'
      ''
      ' ')
    UpdateObject = uqry_lineas
    Left = 376
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_acumxsit: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select c.empaqe as situacion,'
      #9'sum(b.unids * f.factor) as unids,'
      '        sum(b.costou * (b.piva/100+1) * f.factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo and f.idtipovta = 1'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      '        and a.tipo = b.tipo'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join lineas d on c.linea=d.numero'
      
        '        join inv_tpvtatmp g on b.siono = g.tiposal and g.idtipov' +
        'ta = 2'
      '        and f.idtarea = g.idtarea'
      
        '        join inv_tpvtatmp h on b.entcan = h.tiposal and h.idtipo' +
        'vta = 3'
      '        and f.idtarea = h.idtarea'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        group by c.empaqe'
      ''
      ' ')
    Left = 408
    Top = 232
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_acumxlin: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.linea, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot,'
      'sum(0) as cosmesan,'
      'sum(ctocont) as ctocont,'
      'sum(ctocred) as ctocred'
      ''
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      
        '       where d.idtarea = :IDTAREA  and a.fecini between :FECINI ' +
        'and :FECFIN'
      '       and a.cia = :CIA'
      '       and zona2 between  :ZONAINI and :ZONAFIN'
      '       and ptvta2 between :PTVTAINI and :PTVTAFIN'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      'group by a.linea'
      ''
      ' '
      ' '
      ' '
      ' '
      ' ')
    UpdateObject = uqry_acumxlin
    Left = 440
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_acumxpvt: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select ptvta2 as ptvta, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot,'
      'sum(ctocont) as ctocont,'
      'sum(ctocred) as ctocred'
      ''
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      
        '       where d.idtarea = :IDTAREA  and a.fecini between :FECINI ' +
        'and :FECFIN'
      '       and a.cia = :CIA'
      '       and zona2 between  :ZONAINI and :ZONAFIN'
      '       and ptvta2 between :PTVTAINI and :PTVTAFIN'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      'group by ptvta2'
      ''
      ' '
      ' ')
    Left = 472
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_eliminaacuant: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'delete from tabcvta'
      'where fecini = :FECINI and fecfin= :FECFIN'
      'and tipoent= :TIPOENT and cia=:CIA'
      ''
      '')
    Left = 504
    Top = 232
    ParamData = <
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
        DataType = ftUnknown
        Name = 'TIPOENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_acumulados: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.tipo as tipo, c.linea as linea, a.alm as alm,'
      '       b.recemi as ptvta, b.siono as siono,'
      '       sum(b.costou * d.factor) as costo,'
      '       sum (b.costou * factor * b.piva / 100) as iva'
      '       from inv_tpvtatmp d '
      '       join entradas a on d.tiposal = a.tipo'
      '       join renentra b on a.tipo = b.tipo'
      
        '       and a.alm = b.alm and a.numero = b.numero and a.cia = b.c' +
        'ia'
      '       join inven c on b.codinv = c.codigo and b.cia = c.cia'
      '       where d.idtarea= :IDTAREA'
      '       and a.fecha between :FECINI and :FECFIN and a.cia = :CIA'
      '       group by  tipo, linea, alm, ptvta, siono'
      ''
      ' ')
    Left = 312
    Top = 264
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_tabcvta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select * from tabcvta where fecini = :FECINI and fecfin = :FECFI' +
        'N'
      
        'and zona = :ZONA and almkdx = :ALMKDX and ptvta = :PTVTA and lin' +
        'ea = :LINEA'
      'and cia = :CIA'
      ' '
      ' ')
    UpdateObject = uqry_tabcvta
    Left = 313
    Top = 296
    ParamData = <
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
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMKDX'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PTVTA'
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
      end>
  end
  object uqry_tabcvta: TUpdateSQL
    ModifySQL.Strings = (
      'update tabcvta'
      'set'
      '  FECINI = :FECINI,'
      '  FECFIN = :FECFIN,'
      '  ZONA = :ZONA,'
      '  ALMKDX = :ALMKDX,'
      '  PTVTA = :PTVTA,'
      '  LINEA = :LINEA,'
      '  CTOVTASI = :CTOVTASI,'
      '  IVASI = :IVASI,'
      '  CTOVTANO = :CTOVTANO,'
      '  TIPO = :TIPO,'
      '  CIA = :CIA,'
      '  TIPOENT = :TIPOENT,'
      '  CTOCONT = :CTOCONT,'
      '  CTOCRED = :CTOCRED'
      'where'
      '  FECINI = :OLD_FECINI and'
      '  FECFIN = :OLD_FECFIN and'
      '  ZONA = :OLD_ZONA and'
      '  ALMKDX = :OLD_ALMKDX and'
      '  PTVTA = :OLD_PTVTA and'
      '  LINEA = :OLD_LINEA and'
      '  CIA = :OLD_CIA and'
      '  TIPOENT = :OLD_TIPOENT')
    InsertSQL.Strings = (
      'insert into tabcvta'
      
        '  (FECINI, FECFIN, ZONA, ALMKDX, PTVTA, LINEA, CTOVTASI, IVASI, ' +
        'CTOVTANO, '
      '   TIPO, CIA, TIPOENT, CTOCONT, CTOCRED)'
      'values'
      
        '  (:FECINI, :FECFIN, :ZONA, :ALMKDX, :PTVTA, :LINEA, :CTOVTASI, ' +
        ':IVASI, '
      '   :CTOVTANO, :TIPO, :CIA, :TIPOENT, :CTOCONT, :CTOCRED)')
    DeleteSQL.Strings = (
      'delete from tabcvta'
      'where'
      '  FECINI = :OLD_FECINI and'
      '  FECFIN = :OLD_FECFIN and'
      '  ZONA = :OLD_ZONA and'
      '  ALMKDX = :OLD_ALMKDX and'
      '  PTVTA = :OLD_PTVTA and'
      '  LINEA = :OLD_LINEA and'
      '  CIA = :OLD_CIA and'
      '  TIPOENT = :OLD_TIPOENT')
    Left = 343
    Top = 296
  end
  object qry_ubivta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from ubivtainv where alm = :ALM and pvta = :PVTA')
    Left = 376
    Top = 264
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PVTA'
        ParamType = ptUnknown
      end>
  end
  object qry_zonas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.tipo, a.zona, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot'
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      
        '       where d.idtarea = :IDTAREA  and a.fecini between :FECINI ' +
        'and :FECFIN'
      '       and a.cia = :CIA'
      '       and zona2 between  :ZONAINI and :ZONAFIN'
      '       and ptvta2 between :PTVTAINI and :PTVTAFIN'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      'group by a.tipo, a.zona'
      ''
      ' '
      ' ')
    Left = 536
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDTAREA'
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
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_acumxzonlin: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.linea, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot,'
      'sum(ctocont) as ctocont,'
      'sum(ctocred) as ctocred'
      ''
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      
        '       where d.idtarea = :IDTAREA  and a.fecini between :FECINI ' +
        'and :FECFIN'
      '       and a.cia = :CIA'
      '       and zona2 between  :ZONAINI and :ZONAFIN'
      '       and ptvta2 between :PTVTAINI and :PTVTAFIN'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      'group by a.linea'
      ''
      ' '
      ''
      ' ')
    Left = 472
    Top = 266
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_dato_zona_pvta_linea: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.linea, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot,'
      'sum(ctocont) as ctocont,'
      'sum(ctocred) as ctocred'
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      
        '       where d.idtarea = :IDTAREA  and a.fecini between :FECINI ' +
        'and :FECFIN'
      '       and a.cia = :CIA'
      '       and zona2 between  :ZONAINI and :ZONAFIN'
      '       and ptvta2 between :PTVTAINI and :PTVTAFIN'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      'group by a.linea'
      '')
    Left = 472
    Top = 306
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'IDTAREA'
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_exiulcos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select linea, sum(costosi) as exissi,'
      'sum(ivasi) as iva,'
      'sum(costono) as exisno,'
      'sum(costosi + ivasi + costono) as existot'
      ''
      'from resulcosinv where fecha = :FECFIN'
      'and alm between :ALMINI and :ALMFIN'
      'and linea between :LINEAINI and :LINEAFIN'
      'and cia = :CIA and zona between :ZONAINI and :ZONAFIN'
      'group by linea'
      ''
      ''
      ' ')
    Left = 472
    Top = 346
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_zonas2: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.tipo, a.zona, sum(0) as costosi,'
      'sum(0) as iva,'
      'sum(0) as costotot,'
      'sum(0) as exist'
      'from'
      '       inv_tpvtatmp d'
      '       join tabcvta  a on d.tiposal = a.tipoent'
      '       join ubivtainv b on a.almkdx = b.alm and a.ptvta = b.pvta'
      '       where d.idtarea = -1'
      'group by a.tipo, a.zona'
      ''
      ' '
      ' '
      ' '
      ' ')
    UpdateObject = uqry_zonas2
    Left = 568
    Top = 232
  end
  object uqry_zonas2: TUpdateSQL
    Left = 600
    Top = 232
  end
  object uqry_acumxlin: TUpdateSQL
    Left = 440
    Top = 264
  end
  object uqry_lineas: TUpdateSQL
    Left = 600
    Top = 232
  end
  object qry_zonas3: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from zonainv order by tipo, zona'
      '')
    Left = 568
    Top = 264
  end
  object qry_dato_x_tipovta: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.linea, sum(ctovtasi+ctovtano) as costosi,'
      'sum(ivasi) as iva,'
      'sum(ctovtasi + ivasi + ctovtano) as costotot,'
      'sum(ctocont) as ctocont,'
      'sum(ctocred) as ctocred'
      'from'
      
        '       tabcvta  a join ubivtainv b on a.almkdx = b.alm and a.ptv' +
        'ta = b.pvta'
      '       where a.fecini between :FECINI and :FECFIN'
      '       and a.tipoent = :TIPOVTA and a.cia = :CIA'
      '       and linea between :LINEAINI and :LINEAFIN'
      '       and fecini = convert_date('
      '        convert_char(Year(fecfin))+ '#39'-'#39' +'
      '        convert_char(Month(fecfin)) + '#39'-01'#39
      
        '       ) and fecfin =  timestampadd(4, -1, timestampadd(6, 1, fe' +
        'cini))'
      '       and b.ptvta2 between :PTVTAINI and :PTVTAFIN'
      'group by a.linea'
      ''
      ''
      ' ')
    Left = 432
    Top = 306
    ParamData = <
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
        DataType = ftUnknown
        Name = 'TIPOVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PTVTAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_ctovtamay: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.alm, c.linea, sum(b.costou) as costo,'
      'sum(b.costou*(b.piva/100) ) as iva,'
      'sum(b.costou*(b.piva/100 + 1) ) as costotot'
      '       from entradas a join renentra b'
      
        '       on a.tipo = b.tipo and a.numero = b.numero and a.alm = b.' +
        'alm'
      '       and a.cia = b.cia'
      '       join inven c on b.codinv = c.codigo and b.cia = c.cia'
      '       where'
      '       a.fecha between :FECINI and :FECFIN'
      '       and a.tipo = :TIPOVTA and a.cia = :CIA'
      '       and c.linea between :LINEAINI and :LINEAFIN'
      'group by a.alm, c.linea'
      '')
    Left = 432
    Top = 338
    ParamData = <
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
        DataType = ftUnknown
        Name = 'TIPOVTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEAFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_credcont: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select sum(b.costou) as costo, sum(b.costou*(b.piva/100) ) as iv' +
        'a'
      'from entradas a join renentra b on a.tipo = b.tipo'
      'and a.numero = b.numero and a.alm = b.alm and a.cia = b.cia'
      'join inven c on b.codinv = c.codigo and b.cia = c.cia'
      'join ubivtainv d on b.alm = d.alm and b.recemi = d.pvta'
      'where'
      'a.fecha between :FECINI and :FECFIN and a.cia = :CIA'
      'and a.tipo = :TIPOSAL'
      'and a.alm = :ALM and b.recemi = :RECEMI and c.linea = :LINEA'
      'and b.folent = :CREDOCONT'
      '')
    Left = 504
    Top = 306
    ParamData = <
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOSAL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CREDOCONT'
        ParamType = ptUnknown
      end>
  end
  object qry_credoconcancel: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select sum(b.costou) as costo, sum(b.costou*(b.piva/100) ) as iv' +
        'a'
      'from entradas a join renentra b on a.tipo = b.tipo'
      'and a.numero = b.numero and a.alm = b.alm and a.cia = b.cia'
      'join inven c on b.codinv = c.codigo and b.cia = c.cia'
      'join ubivtainv d on b.alm = d.alm and b.recemi = d.pvta'
      'where'
      'a.fecha between :FECINI and :FECFIN and a.cia = :CIA'
      'and a.tipo = :TIPOSAL'
      'and a.alm = :ALM and b.recemi = :RECEMI and c.linea = :LINEA'
      'and b.folsal = :CREDOCONT'
      ''
      ' ')
    Left = 504
    Top = 338
    ParamData = <
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOSAL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'RECEMI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CREDOCONT'
        ParamType = ptUnknown
      end>
  end
  object qry_cartera_cl: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      'select sum(precon) as importe from acuvtas'
      'where'
      'subzona = :PTOVTA and voc = '#39'V'#39
      'and'
      'fecini = convert_date('
      '         convert_char(Year(fecfin))+ '#39'-'#39' +'
      '         convert_char(Month(fecfin)) + '#39'-01'#39
      '       )'
      
        '       and fecfin =  timestampadd(4, -1, timestampadd(6, 1, feci' +
        'ni)'
      ')'
      ''
      'and fecfin between :FECINI and :FECFIN'
      'and'
      '('
      '   (qom = '#39'Q'#39' and letras between :LTAQUININI and :LTAQUINFIN )'
      'or (qom = '#39'M'#39' and letras between :LTAMENINI  and :LTAMENFIN )'
      ')'
      ''
      ' ')
    Left = 408
    Top = 202
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PTOVTA'
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
        DataType = ftUnknown
        Name = 'LTAQUININI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAQUINFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAMENINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAMENFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_cartera_cylp_zona: TQuery
    DatabaseName = 'dbcartera'
    SQL.Strings = (
      'select sum(precon) as importe from acuvtas'
      'where'
      'zona = :ZONA and voc = '#39'V'#39
      'and'
      'fecini = convert_date('
      '         convert_char(Year(fecfin))+ '#39'-'#39' +'
      '         convert_char(Month(fecfin)) + '#39'-01'#39
      '       )'
      
        '       and fecfin =  timestampadd(4, -1, timestampadd(6, 1, feci' +
        'ni)'
      ')'
      ''
      'and fecfin between :FECINI and :FECFIN'
      'and'
      '('
      '   (qom = '#39'Q'#39' and letras between :LTAQUININI and :LTAQUINFIN )'
      'or (qom = '#39'M'#39' and letras between :LTAMENINI  and :LTAMENFIN )'
      ')'
      ''
      ' '
      ' ')
    Left = 442
    Top = 202
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ZONA'
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
        DataType = ftUnknown
        Name = 'LTAQUININI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAQUINFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAMENINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LTAMENFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_ubivtacartera: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from ubivtainv'
      'where'
      'pvta = :PVTA and alm <> '#39'BO'#39' and alm <> '#39#39)
    Left = 408
    Top = 264
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PVTA'
        ParamType = ptUnknown
      end>
  end
end
