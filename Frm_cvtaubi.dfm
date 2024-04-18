object Form_cvtaubi: TForm_cvtaubi
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
    object grp_netobru: TRadioGroup
      Left = 180
      Top = 0
      Width = 100
      Height = 137
      Align = alLeft
      Caption = 'Reporte de'
      ItemIndex = 0
      Items.Strings = (
        'Ventas Brutas'
        'Ventas Netas'
        'Cancelaciones')
      TabOrder = 1
    end
    object grp_statcan: TRadioGroup
      Left = 280
      Top = 0
      Width = 130
      Height = 137
      Align = alLeft
      Caption = 'Status de Cancelación'
      ItemIndex = 0
      Items.Strings = (
        'Todo'
        'Solo de Cancelacion'
        'Solo No Cancelados')
      TabOrder = 2
    end
    object grp_statsino: TRadioGroup
      Left = 410
      Top = 0
      Width = 100
      Height = 137
      Align = alLeft
      Caption = 'Status Si/No'
      ItemIndex = 0
      Items.Strings = (
        'Todo'
        'Solo Status 1'
        'Solo Status 2')
      TabOrder = 3
    end
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
      end
    end
    object BitBtn1: TBitBtn
      Left = 85
      Top = 88
      Width = 75
      Height = 25
      Action = imprimir_reporte
      Caption = 'Reporte'
      Default = True
      ModalResult = 1
      TabOrder = 4
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000FF00FF0000000000BDBD
        BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
        BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000BDBD
        BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
        BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000000000FFFF
        FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
        FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD000000000000000000BDBD
        BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBD
        BD00FFFFFF00BDBDBD00FFFFFF000000FF00FFFFFF000000000000000000FFFF
        FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
        FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
        FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000BDBDBD00FFFFFF0000000000FFFF
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      NumGlyphs = 2
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
      'select c.linea, d.orden, c.codigo, c.descri, c.empaqe,'
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
      '        group by linea, d.orden, codigo,c.descri,c.empaqe'
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
      ImageIndex = 21
      OnExecute = imprimir_reporteExecute
    end
  end
  object qry_analixalm: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select i.ptvta2 as recemi,'
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
      '        join ubivtainv i on b.alm = i.alm and b.recemi = i.pvta'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        and c.linea = :LINEA'
      '        group by i.ptvta2'
      '')
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
      'select i.ptvta2 as recemi, b.codinv,'
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
      '        join ubivtainv i on b.alm = i.alm and b.recemi = i.pvta'
      '        where'
      '        f.idtarea = :IDTAREA and f.idtipovta = 1'
      '        and a.fecha between :FECINI and :FECFIN and a.cia= :CIA'
      '        and b.codinv = :CODIGO'
      '        group by i.ptvta2, b.codinv'
      '')
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
      'select * from lineas where numero = :LINEA and cia = :CIA')
    Left = 376
    Top = 232
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
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
      'select c.linea,'
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
      '        group by c.linea'
      ''
      ' ')
    Left = 440
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
  object qry_acumxpvt: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select b.recemi as pvta,'
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
      '        group by b.recemi'
      ''
      ' ')
    Left = 472
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
end
