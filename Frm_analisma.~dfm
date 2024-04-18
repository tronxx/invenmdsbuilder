object Form_analisma: TForm_analisma
  Left = 254
  Top = 149
  Width = 696
  Height = 480
  Caption = 'Analítico de Costo de Ventas/Cancelaciones/Mayoreo'
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
    Height = 138
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object grp_tiporep: TRadioGroup
      Left = 180
      Top = 0
      Width = 100
      Height = 138
      Align = alLeft
      Caption = 'Reporte de'
      ItemIndex = 0
      Items.Strings = (
        'Menudeo'
        'Mayoreo'
        'Fonacot'
        'Fide'
        'Celular'
        'Entradas')
      TabOrder = 0
    end
    object grp_netobru: TRadioGroup
      Left = 280
      Top = 0
      Width = 100
      Height = 138
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
      Left = 380
      Top = 0
      Width = 130
      Height = 138
      Align = alLeft
      Caption = 'Status de Cancelación'
      ItemIndex = 0
      Items.Strings = (
        'Sin Importar Status'
        'Cancelacion'
        'No Cancelados')
      TabOrder = 2
    end
    object grp_statsino: TRadioGroup
      Left = 510
      Top = 0
      Width = 100
      Height = 138
      Align = alLeft
      Caption = 'Status Si/No'
      ItemIndex = 0
      Items.Strings = (
        'Sin Importar'
        'Solo Status 1'
        'Solo Status 2')
      TabOrder = 3
    end
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 180
      Height = 138
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 4
      object Label1: TLabel
        Left = 7
        Top = 16
        Width = 60
        Height = 13
        Caption = 'Fecha Inicial'
      end
      object Label2: TLabel
        Left = 12
        Top = 40
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object lbl_alm: TLabel
        Left = 26
        Top = 66
        Width = 41
        Height = 13
        Caption = 'Almacén'
        Visible = False
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
      end
      object btn_ejecutar: TBitBtn
        Left = 85
        Top = 104
        Width = 75
        Height = 25
        Action = genera_analisma
        Caption = 'Analisma'
        TabOrder = 3
        Kind = bkOK
      end
      object edt_almini: TEdit
        Left = 77
        Top = 62
        Width = 97
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 2
        Visible = False
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 138
    Width = 688
    Height = 308
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
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LINEA'
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
    object dbgrd_renglonesCOSTOU: TdxDBGridCurrencyColumn
      Caption = 'Costo Unit'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOU'
    end
    object dbgrd_renglonesPRVTA: TdxDBGridCurrencyColumn
      Caption = 'Precio.Vta'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PRVTA'
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
      'select d.orden, c.linea, c.codigo, c.descri, c.empaqe, b.costou,'
      #9'b.prvta * (b.piva/100+1) as prvta,'
      #9'sum(b.unids * factor) as unids,'
      '        sum(b.costou * (b.piva/100+1) * factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join lineas d on c.linea=d.numero'
      '        where'
      
        '        f.idtarea = :IDTAREA and a.fecha between :FECINI and :FE' +
        'CFIN and a.cia= :CIA'
      '        and (b.siono  = :SIONO1  or b.siono  = :SIONO2)'
      '        and (b.entcan = :ENTCAN1 or b.entcan = :ENTCAN2)'
      
        '        group by d.orden,linea,codigo,c.descri,c.empaqe, costou,' +
        'prvta'
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
      end
      item
        DataType = ftString
        Name = 'SIONO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SIONO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN1'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN2'
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
  end
  object ActionList1: TActionList
    Left = 552
    Top = 280
    object exporta_dbgrd: TAction
      Caption = 'Exportar a...'
      OnExecute = exporta_dbgrdExecute
    end
    object acum_cob_mayo: TAction
      Caption = 'Acumulado Cobranza'
      OnExecute = acum_cob_mayoExecute
    end
    object genera_analisma: TAction
      Caption = 'Analisma'
      OnExecute = genera_analismaExecute
    end
    object reporte_analimvm: TAction
      Caption = 'Analítico Mov.Mayoreo'
    end
    object reporte_repcvta: TAction
      Caption = 'Reporte'
      OnExecute = reporte_repcvtaExecute
    end
  end
  object qry_abonos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select a.mayoris, a.fecha, a.tipago, sum(a.importe) as importe'
      'from movmay2 a'
      
        'where a.fecha between :FECINI and :FECFIN and a.coa='#39'A'#39' and a.ci' +
        'a= :CIA'
      'group by a.mayoris, a.fecha, a.tipago'
      ''
      ' '
      ' ')
    Left = 312
    Top = 240
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
      end>
  end
  object qry_datopago: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select sum(a.importe) as importe'
      #9'from movmay2 a join movmay2 b on a.mayoris = b.mayoris'
      
        '        and a.docto = b.docto and a.pagare = b.pagare and a.cia=' +
        'b.cia'
      '        and b.coa = '#39'C'#39
      
        '        where a.mayoris= :MAYORISTA  and a.fecha = :FECHA and a.' +
        'coa='#39'A'#39
      '        and a.tipago = :TIPAGO and a.cia = :CIA')
    Left = 336
    Top = 240
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'MAYORISTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPAGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_invulcos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.* from invulcos a where a.codigo = :CODIGO and a.cia = ' +
        ':CIA'
      'and fecha = (select max(fecha) from invulcos b'
      
        'where b.codigo = a.codigo and b.cia = a.cia and b.fecha <= :FECO' +
        'RTE)'
      '')
    UpdateObject = uqry_gpodiary
    Left = 368
    Top = 240
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
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end>
  end
end
